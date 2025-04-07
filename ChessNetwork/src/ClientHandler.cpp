//
// Created by jordan on 3/30/2025.
//
// It's a chess client class. It represents a single connection from somewhere.

#include <ChessCoordinate.h>
#include <ChessNetwork.h>
#include <ClientHandler.h>
#include <iostream>
#include <json.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core/buffers_to_string.hpp>


ClientHandler::ClientHandler  (
    tcp::socket socket,
    std::function<std::string(const std::string&, const std::string& b)> callBack,
    std::weak_ptr<IClientEvents> event, // Now takes interface
    strand<boost::asio::any_io_executor> strand
) : events_(std::move(event)), strand_(std::move(strand))
{
    websocket_.emplace(std::move(socket));
    onMessageReceived_callback = callBack;
}

// But when will it close?
ClientHandler::~ClientHandler() {
    if (websocket_ && websocket_->is_open()) {
        websocket_->close(boost::beast::websocket::close_code::normal);
    }
}

// Does the handshake, maybe combine this with handleHandShake??? It's really short.



void ClientHandler::start(std::function<void()> onHandshakeComplete) {
        websocket_->async_accept([self = shared_from_this(), onHandshakeComplete ](const boost::system::error_code &ec) {
            self->handleHandshake(ec);   // shared_from_this() returns a shared pointer, which we use to avoid scoping issues.
            if(!ec && onHandshakeComplete) {
                onHandshakeComplete();
            }

    });
}


void ClientHandler::handleHandshake(boost::system::error_code ec) {
    if (!ec) {
        std::cout << "WebSocket handshake successful!" << std::endl;
        //
        // I think we need to use strand_ here.
        post(strand_, [this]() {
            try {
                nlohmann::json jsonResponse;
                // This is the move data.
                // {"type":"move","from":{"row":6,"col":4},"to":{"row":4,"col":4}}

                ChessCoordinate from{0,0};
                // Send an invalid move so the server responds with board data.

                jsonResponse["valid"] = true;
                jsonResponse["from"] = { {"row", from.row}, {"col", from.col} };
                jsonResponse["to"] = { {"row", from.row}, {"col", from.col} };

                // This however doesn't sent anything to the client hmm..
                std::string rst = onMessageReceived_callback(jsonResponse.dump(), "spectator");
                //this->sendMessage(rst);

            } catch (const std::exception &e) {
                std::cout << e.what();
            }
        });

        receiveMessageAsync();  // Start receiving messages

    } else {
        std::cerr << "WebSocket handshake failed: " << ec.message() << std::endl;
    }
}


/**
 *  This receives the message from the REACT client.
 */
void ClientHandler::receiveMessageAsync() {

    // Check if the socket has been closed
    if (websocket_->is_open() == false) {
        std::cerr << "Socket is already closed. No more reads will be attempted." << std::endl;
        return;  // Don't try to read if the socket is closed
    }

    /** Shared buffer to persist!! A BIG bug here was using a flat_buffer allocated on the stack.
     *  Remember things don't go top down, so it would go out of scope instantly and I would get a memory error.
     *  the async_read doesn't wait it just returns immediatley if I"m correct. so you do need to pass a shared ptr in
     *  for it to not go out of scope instantly
     */
    auto self = shared_from_this();
    auto buffer = std::make_shared<boost::beast::flat_buffer>();

    websocket_->async_read(*buffer, [self, buffer](boost::system::error_code ec, std::size_t bytes_transferred) {
        // Connection aborted is when you close the client.
        if(ec == boost::asio::error::eof || ec == boost::asio::error::connection_aborted ) {
            std::cout << "Client disconnected!!!!!!!!!" << std::endl;
            if (self->websocket_ && self->websocket_->is_open()) {
                self->websocket_->close(boost::beast::websocket::close_code::normal);
            }

            if(auto events_shared = self->events_.lock()) {
                 events_shared->onDisconnect(self);
            }

            return;
        }


        // Lambda function occurs after the read is done!
        if (!ec) {
            std::string message = boost::beast::buffers_to_string(buffer->data());
            std::cout << "Received message in ClientHandler.cpp: " << message << std::endl;
            if (self->onMessageReceived_callback) {
                try {
                    std::string rst = self->onMessageReceived_callback(message, self->client_info.color);
                    std::cout << rst << std::endl;

                    if(auto events_shared = self->events_.lock()) {
                        //self->sendMessage(rst); // Sends the message to the the single REACT client.
                         events_shared->broadcastToAll(rst);
                     }

                } catch (const std::exception& e) {
                    std::cerr << "Callback execution failed: " << e.what() << std::endl;
                }
            }
        } else {
            std::cerr << "Error receiving message: " << ec.message() << std::endl;
        }

        self->receiveMessageAsync();
    });
}

// This sends the message to REACT client that corresponds the single Client you have somewhere.
void ClientHandler::sendMessage(const std::string& message) {

    boost::asio::post(strand_, [self = shared_from_this(), message]() {
        self->websocket_->async_write(boost::asio::buffer(message.data(), message.size()),


            [self](boost::system::error_code ec, std::size_t bytes_transferred) {
                if (ec) {
                    std::cerr << "Error from WebSocket, unable to send: " << ec.message() << " bytes " << bytes_transferred << std::endl;
                }
            });

    });

}