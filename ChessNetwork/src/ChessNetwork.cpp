//
// Created by jordan on 3/20/2025.
//
// It's a chess network class, it designed to send and recieve input from the client.
#include <iostream>
#include "ChessNetwork.h"


ChessNetwork::ChessNetwork()
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), 8080))
{
    try {
        std::cout << "Waiting for a connection...." << std::endl;
        // Start accepting connections asynchronously
        acceptConnection();
    } catch (const std::exception &e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }

}


ChessNetwork::~ChessNetwork() = default;

/**
 * Accepts the connection from client and does handshake.
 */
void ChessNetwork::acceptConnection() {
    acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) {
            // Create the ClientHandler and pass the socket to it
            auto client = std::make_shared<ClientHandler>(std::move(socket), onMessageReceived_callback);
            clientList.push_back(client); // Track the client

            // Start handling WebSocket connection
            client->start();
        }

        // Continue accepting new connections
        acceptConnection();
    });
}




// Takes in a function as an input, and moves it here!
void ChessNetwork::setMessageReceivedCallback(std::function<std::string(const std::string&)> callback) {
    onMessageReceived_callback = std::move(callback);
}


void ChessNetwork::startNetworkLoop() {
    ctx.run(); // As long as there's async operations it will keep running.
}

