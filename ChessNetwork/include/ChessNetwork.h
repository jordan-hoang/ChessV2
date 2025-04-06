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
#include "IClientEvents.h"


using boost::asio::ip::tcp;
using namespace boost::beast;

// Observer is an interface more or less.
// It's the "Subject because it's being observed by the clients.
class ChessNetwork : public IClientEvents, public std::enable_shared_from_this<ChessNetwork> {
    public:
        ChessNetwork();
        ~ChessNetwork();

        // Runs the ctx.
        void startNetworkLoop();

        // **New Method to Set the Callback for recieving messages? **
        // You may want to use shared pointer or pass by reference.
        void setMessageReceivedCallback(std::function<std::string(const std::string&, const std::string&)> callback);

        void removeClient(std::shared_ptr<ClientHandler> client);

        std::string determineClientRole(); // Checks the clients colors. Returns 1 if they need to be white, returns 2 if black, return 3 for no color.


    protected:
        // Client → Network notifications
        void onDisconnect(std::shared_ptr<ClientHandler> client) override;
        // Network → Client broadcasting
        void broadcastToAll(const std::string& message) override;


    private:
        boost::asio::io_context ctx;    // I/O context for ASIO
        std::vector<std::shared_ptr<ClientHandler>> clientList; // A list of all the clients we have "accepted"
        tcp::acceptor acceptor_;        // Accepts connections from clients.
        std::function<std::string(const std::string&, const std::string&)> onMessageReceived_callback; // Callback function!!! First time seeing this.

        strand<io_context::executor_type> strand_;


        // Starts accepting connections. Called by constructor and doesn't stop.
        void acceptConnection();
};



#endif //NETWORK_H
