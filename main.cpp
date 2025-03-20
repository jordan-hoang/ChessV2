#include "ChessController.h"






#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;
namespace beast = boost::beast;
namespace websocket = beast::websocket;

void mySession1(tcp::socket socket) {
    try {

        websocket::stream<tcp::socket> ws(std::move(socket));
        ws.accept();

        std::cout << "Client connected!" << std::endl;

        for (;;) {
            beast::flat_buffer buffer;
            ws.read(buffer); // Read from the websocket.

            std::string message = beast::buffers_to_string(buffer.data());
            std::cout << "Received: " << message << std::endl;

            // Echo the message back
            ws.text(ws.got_text());
            ws.write(boost::asio::buffer(message + " Hello World"));

        }

    } catch (const std::exception& e) {
        std::cerr << "Session error: " << e.what() << std::endl;
    }
}

void testFunc2() {

    try {
        boost::asio::io_context ioc;
        tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 9002)); // Uses port 9002

        std::cout << "WebSocket server started on ws://localhost:9002" << std::endl;

        for (;;) { // Why this for loop?
            tcp::socket socket(ioc);
            acceptor.accept(socket);
            std::thread(&mySession1, std::move(socket)).detach();
        }

    }  catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }


}




int main() {

    ChessController chessGame;
    chessGame.run();
    chessGame.wait();
    // testFunc();

    return 0;
}



