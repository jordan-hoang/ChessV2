//
// Created by jorda on 3/20/2025.
//

#ifndef NETWORK_H
#define NETWORK_H


#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>


using boost::asio::ip::tcp;
using namespace boost::beast;

class ChessNetwork {

    private:
        boost::asio::io_context ctx;         // I/O context for ASIO
        tcp::acceptor acceptor_;   // Accepts connections from clients.
        std::optional<boost::beast::websocket::stream<tcp::socket>> websocket_;  // Optional WebSocket


        void session(tcp::socket socket);
        void do_accept();
        void do_session(tcp::socket socket);

    public:
        ChessNetwork(unsigned short port);
        ChessNetwork();
        ~ChessNetwork();

        void send(const std::string &message);

        void async_send(const std::string &message); // Not used.

        std::string receive();


};



#endif //NETWORK_H
