//
// Created by jordan on 3/20/2025.
//



#include <iostream>

#include "ChessNetwork.h"


// NOT DONE
ChessNetwork::ChessNetwork(unsigned short port)
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), port))
{

}


ChessNetwork::ChessNetwork()
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), 8080))
{

    try {
        tcp::socket socket(ctx);

        std::cout << "Waiting for a connection...." << std::endl;
        acceptor_.accept(socket); // Sync Accept, will hang until it receives one.
        std::cout << "Connection accepted!" << std::endl;

        websocket_.emplace(std::move(socket)); // This can also be a unique_ptr
        std::cout << "WebSocket initialized!" << std::endl;

        boost::system::error_code ec;
        websocket_->accept(ec);
        if (!ec) {
            std::cout << "WebSocket handshake successful!" << std::endl;
            if (websocket_->is_open()) {
                std::cout << "WebSocket opened!" << std::endl;
            }
        } else {
            std::cout << "WebSocket handshake failed: " << ec.message() << std::endl;
        }

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


// Sends a message through the websocket.
void ChessNetwork::send(const std::string &message) {
    if(websocket_ && websocket_->is_open()) {
        boost::system::error_code ec;
        websocket_->write(boost::asio::buffer(message), ec);
        if(!ec) {
            std::cerr << "Send error: " << ec.message() << std::endl;
        }
    }
}


// This function isn't used! We have a blocking send instead, I just left this here in case we want to do one for some reason?
void ChessNetwork::async_send(const std::string &message) {
    if(websocket_ && websocket_->is_open()) {
        websocket_->async_write(boost::asio::buffer(message),
            [this](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "Send error: " << ec.message() << std::endl;
            }
        });
    }
}


// Recieve a message from the websocket / website.
std::string ChessNetwork::receive() {

    boost::beast::flat_buffer buffer; // No need for shared_ptr, just use flat_buffer

    if(websocket_ && websocket_->is_open()) {
        boost::system::error_code ec;
        websocket_->read(buffer, ec);
        if(!ec) {
            std::cout << "Received message: " << buffers_to_string(buffer.data()) << std::endl;
            return buffers_to_string(buffer.data());
        } else {
            return "FAILURE";
        }

    }

    std::cerr << "ChessNetwork::receive(), socket is not OPEN!\n"; // Shouldn't be possible, constructor should do it.
    exit(-1);
    return "SOCKET NOT OPEN!!\n";
}

