//
// Created by jorda on 3/20/2025.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>

class ChessNetwork {

    private:
        boost::asio::io_context ioc;

    public:
        void run();
        void mySession1(boost::asio::ip::tcp::socket socket);

        void dummy();

};



#endif //NETWORK_H
