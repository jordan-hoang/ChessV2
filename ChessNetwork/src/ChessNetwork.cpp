//
// Created by jordan on 3/20/2025.
//
// It's a chess network class, it designed to send and recieve input from the client.
#include <iostream>
#include "ChessNetwork.h"


// NOT DONE, DOESN"T DO ANYTHING.
ChessNetwork::ChessNetwork(unsigned short port)
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), port))
{}

/**
 * Accepts the connection from client and does handshake.
 */
void ChessNetwork::startAcceptConn() {
    // The socket represents the new connection, the moment a CLIENT acceepts and the handshake happens.
    // Boost.ASIO automatically calls the lambda and provides these 2 parameters.
    acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket)
    {
        // Only accept 1 client!
        if (!ec && !websocket_) {

            std::cout << "Client connected!" << std::endl;
            // Create the WebSocket session
            websocket_.emplace(std::move(socket)); // Upgrade this into an array for multiple websockets in future....
            websocket_->async_accept([this](boost::system::error_code ec) {
                if (!ec) {
                    std::cout << "WebSocket handshake successful!" << std::endl;
                    if (websocket_->is_open()) {
                        std::cout << "WebSocket opened!" << std::endl;
                        this->receiveMessageAsync(); // Start receiving messages, by using the lambda!
                    }
                } else {
                    std::cerr << "WebSocket handshake failed: " << ec.message() << std::endl;
                }
            });
        }
        // Continue accepting new connections, recursive.
        startAcceptConn();
    });

}

ChessNetwork::ChessNetwork()
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), 8080))
{
    try {
        std::cout << "Waiting for a connection...." << std::endl;
        // Start accepting connections asynchronously
        startAcceptConn();
    } catch (const std::exception &e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }

}

ChessNetwork::~ChessNetwork() {
    // This isn't necessary but nice to do....
    if (websocket_ && websocket_->is_open()) {
        websocket_->close(boost::beast::websocket::close_code::normal);
    }
}

// Takes in a function as an input, and moves it here!
void ChessNetwork::setMessageReceivedCallback(std::function<bool(const std::string&)> callback) {
    onMessageReceived_callback = std::move(callback);
}

// Execute the callback!
void ChessNetwork::receiveMessageAsync() {

    /** Shared buffer to persist!! A BIG bug here was using a flat_buffer allocated on the stack.
     *  Remember things don't go top down, so it would go out of scope instantly and I would get a memory error.
     *  the async_read doesn't wait it just returns immediatley if I"m correct. so you do need to pass a shared ptr in
     *  for it to not go out of scope instantly
     */
    auto buffer = std::make_shared<boost::beast::flat_buffer>();
    websocket_->async_read(*buffer,
        [this, buffer](boost::system::error_code ec, std::size_t bytes_transferred) {
            if (!ec) {

                if (buffer->size() > 0) {
                    std::string message = boost::beast::buffers_to_string(buffer->data());
                    std::cout << "Message received: " << message << std::endl;
                    if (onMessageReceived_callback) {
                        bool rst = onMessageReceived_callback(message);
                         if(rst) { sendMessageAsync("True"); }
                    }
                } else {
                    std::cerr << "Warning: Buffer is empty, but bytes were transferred." << std::endl;
                }

                this->receiveMessageAsync(); // Keep listening for messages, we can probably do a better job.
            } else {
                std::cerr << "Error from WebSocket: " << ec.message() << std::endl;
            }
        });

}


// Send a specific message to the client.
// void ChessNetwork::async_send(const std::string &message) {
//     if (!websocket_ || !websocket_->is_open()) {
//         std::cerr << "WebSocket is not open. Cannot send message." << std::endl;
//         return;
//     }
//
//     websocket_->async_write(boost::asio::buffer(message),
//     [this](boost::system::error_code ec, std::size_t bytes_transferred) {
//         if (ec) {
//             std::cerr << "Error from WebSocket, unable to send: " << ec.message() << " bytes " << bytes_transferred << std::endl;
//         }
//     });
//
// }

// Send a specific message to the client.
void ChessNetwork::sendMessageAsync(const std::string &message) {
    if (!websocket_ || !websocket_->is_open()) {
        std::cerr << "WebSocket is not open. Cannot send message." << std::endl;
        return;
    }

    /** This was the old way I did it, you would then have the lambda capture the buffer for it to not go out of scope.
    *   Just leaving it here for knowledge purposes.
    *
    *   auto buffer = std::make_shared<std::string>(message); // Shared string keeps data alive.
    *   websocket_->async_write(boost::asio::buffer(*buffer),
    */
    websocket_->async_write(boost::asio::buffer(message.data(), message.size()),
        [this](boost::system::error_code ec, std::size_t bytes_transferred) {
            if (ec) {
                std::cerr << "Error from WebSocket, unable to send: "
                          << ec.message() << " bytes " << bytes_transferred << std::endl;
            }
        });
}




void ChessNetwork::startNetworkLoop() {
    ctx.run(); // As long as there's async operations it will keep running.
}
