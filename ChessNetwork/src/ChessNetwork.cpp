//
// Created by jordan on 3/20/2025.
//
// It's a chess network class, it designed to send and recieve input from the client.
#include <iostream>
#include "ChessNetwork.h"

#include <json.hpp>


ChessNetwork::ChessNetwork()
    : acceptor_(ctx, tcp::endpoint(tcp::v4(), 8080)),
      strand_(ctx.get_executor())
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
    acceptor_.async_accept(
        boost::asio::bind_executor(strand_,
        [this](boost::system::error_code ec, tcp::socket socket) {

            if (!ec)
            {
                static std::atomic<uint32_t> client_counter{1};
                uint32_t new_id = client_counter++;

                auto client = std::make_shared<ClientHandler>(
                        std::move(socket),
                        onMessageReceived_callback,
                        weak_from_this(),
                        strand_
                );

                client->client_info.id = new_id;
                client->client_info.color = determineClientRole();
                nlohmann::json jsonResponse;
                jsonResponse["client_role"] = client->client_info.color;


                clientList.push_back(client); // Track the client
                client->start(
                    [client, jsonResponse]() {
                        client->sendMessage(jsonResponse.dump());
                    }
                );             // Start handling WebSocket connection

                //client->sendMessage(jsonResponse.dump()); // Send the role out to the client.
            }

        // Continue accepting new connections
        acceptConnection();
    }));
}

/**
 * This definatley can be simplified, maybe using bits.
 * @return Returns the string of the clients role
 */
std::string ChessNetwork::determineClientRole() {

    bool hasBlack = false;
    bool hasWhite = false;

    for (auto client : clientList) {
        std::string color = client->client_info.color; // Assuming getter exists
        hasWhite = hasWhite || (color == "white");
        hasBlack = hasBlack || (color == "black");
    }

    if (!hasWhite) return "white";
    if (!hasBlack) return "black";
    return "spectator";

}



void ChessNetwork::removeClient(std::shared_ptr<ClientHandler> client){
    auto it = std::find(clientList.begin(), clientList.end(), client);
    if(it != clientList.end()) {
        clientList.erase(it);  // Remove client from the list
    }
}

// Takes in a function as an input, and moves it here!
void ChessNetwork::setMessageReceivedCallback(std::function<std::string(const std::string&, const std::string&)> callback) {
    onMessageReceived_callback = std::move(callback);
}

void ChessNetwork::startNetworkLoop() {
    ctx.run(); // As long as there's async operations it will keep running.
}

// From IClientEvents (client → network)
void ChessNetwork::onDisconnect(std::shared_ptr<ClientHandler> client) {
    boost::asio::post(strand_, [this, client]() {
        auto it = std::find(clientList.begin(), clientList.end(), client);
        if(it != clientList.end()) {
            clientList.erase(it);  // Remove client from the list
        }
        std::cout << "Client disconnected. Total: " << clientList.size() << "\n";
    });
}

// From IClientEvents (network → clients)
void ChessNetwork::broadcastToAll(const std::string& message) {
    post(strand_, [this, message]() {
        for(const auto& client : clientList) {
            client->sendMessage(message);
        }
    });
}
