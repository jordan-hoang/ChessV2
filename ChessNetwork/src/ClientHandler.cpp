//
// Created by jordan on 3/30/2025.
//
// It's a chess client class. It represents a single connection from somewhere.

#include <ChessNetwork.h>
#include <ClientHandler.h>
#include <iostream>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core/buffers_to_string.hpp>





ClientHandler::ClientHandler  (
    tcp::socket socket,
    std::function<std::string(const std::string &)> callBack,
    ChessNetwork* chessNetwork,
    strand<io_context::executor_type> &strand
) : strand_(strand)
{
    websocket_.emplace(std::move(socket));
    onMessageReceived_callback = callBack;
    chess_network_ = chessNetwork;
}


// But when will it close?
ClientHandler::~ClientHandler() {
    if (websocket_ && websocket_->is_open()) {
        websocket_->close(boost::beast::websocket::close_code::normal);
    }
}




// Does the handshake, honestly maybe combine this with handleHandShake??? It's really short.
//
void ClientHandler::start() {
    websocket_->async_accept([self = shared_from_this() ](const boost::system::error_code &ec) {
        self->handleHandshake(ec);   // shared_from_this() returns a shared pointer, which we use to avoid scoping issues.
    });
}


void ClientHandler::handleHandshake(boost::system::error_code ec) {
    if (!ec) {
        std::cout << "WebSocket handshake successful!" << std::endl;
        receiveMessageAsync();  // Start receiving messages
    } else {
        std::cerr << "WebSocket handshake failed: " << ec.message() << std::endl;
    }
}


/**
 *  This receives the message from the REACT client.
 */
void ClientHandler::receiveMessageAsync() {

    /** Shared buffer to persist!! A BIG bug here was using a flat_buffer allocated on the stack.
     *  Remember things don't go top down, so it would go out of scope instantly and I would get a memory error.
     *  the async_read doesn't wait it just returns immediatley if I"m correct. so you do need to pass a shared ptr in
     *  for it to not go out of scope instantly
     */
    auto self = shared_from_this();
    auto buffer = std::make_shared<boost::beast::flat_buffer>();

    websocket_->async_read(*buffer, [self, buffer](boost::system::error_code ec, std::size_t bytes_transferred) {


        // Lambda function occurs after the read is done!
        if (!ec) {

            std::string message = boost::beast::buffers_to_string(buffer->data());
            std::cout << "Received message in ClientHandler: " << message << std::endl;

            if (self->onMessageReceived_callback) {
                try {
                    std::string rst = self->onMessageReceived_callback(message);
                    //self->sendMessage(rst); // Sends the message to the REACT client.

                    self->chess_network_->sendToAll(rst); // SENDS the message to ALL REACT clients.


                } catch (const std::exception& e) {
                    std::cerr << "Callback execution failed: " << e.what() << std::endl;
                }
            }

        } else {
            std::cerr << "Error receiving message: " << ec.message() << std::endl;
        }

        self->receiveMessageAsync();  // Continue reading

    });


}

// This sends the message to REACT client.
void ClientHandler::sendMessage(const std::string& message) {

    auto buffer = std::make_shared<boost::beast::flat_buffer>();
    /** This was the old way I did it, you would then have the lambda capture the buffer for it to not go out of scope.
    *   Just leaving it here for knowledge purposes.
    *
    *   auto buffer = std::make_shared<std::string>(message); // Shared string keeps data alive.
    *   websocket_->async_write(boost::asio::buffer(*buffer),
    */



    boost::asio::post(strand_, [self = shared_from_this(), message]() {

        self->websocket_->async_write(boost::asio::buffer(message.data(), message.size()),
            [self](boost::system::error_code ec, std::size_t bytes_transferred) {
                if (ec) {
                    std::cerr << "Error from WebSocket, unable to send: "
                              << ec.message() << " bytes " << bytes_transferred << std::endl;
                }
            });

    });




}