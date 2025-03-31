//
// Created by jorda on 3/20/2025.
//

#ifndef NETWORK_H
#define NETWORK_H

#pragma once

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include "ClientHandler.h"

using boost::asio::ip::tcp;
using namespace boost::beast;

class ChessNetwork {
    public:
        ChessNetwork();
        ~ChessNetwork();

        void startServer();                              // UNIMPLEMENTED
        void stopServer();                               // UNIMPLEMENTED
        void sendToAll(const std::string &message);      // UNIMPLEMENTED

        void acceptConnection();


        // Public Methods
        void receiveMessageAsync();

        // **New Method to Set the Callback for recieving messages? **
        // You may want to use shared pointer or pass by reference.
        void setMessageReceivedCallback(std::function<std::string(const std::string&)> callback);


        void startNetworkLoop();
        void sendMessageAsync(const std::string &message); // Not used.


    private:
        boost::asio::io_context ctx;    // I/O context for ASIO
        std::vector<std::shared_ptr<ClientHandler>> clientList; // A list of all the clients we have "accepted"
        tcp::acceptor acceptor_;        // Accepts connections from clients.





        std::optional<boost::beast::websocket::stream<tcp::socket>> websocket_;  // Optional WebSocket, can be ptr/smrtptr.

        /// std::vector<std::shared_ptr<websocket::stream<tcp::socket>>> listWebsockets_; Do this later.
        std::function<std::string(const std::string&)> onMessageReceived_callback; // Callback function!!! First time seeing this.

        void session(tcp::socket socket);
        void startAcceptConn();

};



#endif //NETWORK_H
