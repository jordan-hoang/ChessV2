#include "ChessController.h"

#include <iostream>
#include <string>
#include <string_view>

#include <boost/asio/ip/address.hpp>
#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

boost::asio::ip::address ip_address_v4 = boost::asio::ip::make_address("127.0.0.1");
const boost::asio::ip::udp::endpoint SERVER_ENDPOINT(ip_address_v4, 9001);

// Simple server client model, not used for anything just for learning.
void Server() {
    using namespace boost::asio;
    // async i/o
    io_context ctx; // A queue.
    ip::udp::socket serverSocket(ctx, SERVER_ENDPOINT);

    char data[1024];
    serverSocket.async_receive
    (
        buffer(data, 1024),
        [&](std::error_code ec, size_t bytesReceived)
        {
            if(!ec &&  bytesReceived > 0) {
                std::cout << "RCV: " <<  std::string_view(data, bytesReceived) << std::endl;
            }
            else {
                std::cout << "ERROR!: 111 " << ec.message() << std::endl;
            }
        }
    );

    ctx.run(); // Keeps running until the queue is empty. Will always need this, can run on threads.

}

void Client() {
    using namespace boost::asio;
    io_context ctx;

    ip::udp::socket clientSocket(ctx,
        ip::udp::endpoint(ip::udp::v4(), 0)); // 0 means anyport.

    std::string message = "HELLO WORLD";
    clientSocket.async_send_to(
        buffer(message.data(), message.size()),
        SERVER_ENDPOINT,
        [](std::error_code ec, std::size_t byteSent) {

                if(!ec && byteSent > 0) {
                    std::cout << " Bytes sent successfully: " << byteSent << std::endl;
                } else {
                    std::cout << "ERROR!:  " << ec.message() << std::endl;
                }
            }
    );

    ctx.run();
}

int dummyMain(int argc, char ** argv) {


    if (argc == 2) {
        std::string appName = argv[1];
        if(appName == "server") {
            Server();
            return 0;
        }
        else if (appName == "client") {
            Client();
            return 0;
        }
    }

    std::cout << "Usage: Chess [server/client]";
    return 0;


}

int main() {

    ChessController chessGame;
    chessGame.run();
    chessGame.wait();

}


