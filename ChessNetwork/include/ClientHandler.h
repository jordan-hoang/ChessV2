
#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include <memory>
#include <optional>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket/stream.hpp>

using namespace boost::asio;

/**
* Represents a single client for the chess project.
*/
class ClientHandler : public std::enable_shared_from_this<ClientHandler> {
    private:
        std::optional<boost::beast::websocket::stream<boost::asio::ip::tcp::socket>> websocket_;
        std::function<std::string(const std::string&)> onMessageReceived_callback; // The call back function

    public:
        explicit ClientHandler(ip::tcp::socket); // ju
        ClientHandler(ip::tcp::socket socket, std::function<std::string(const std::string &)> callBack);
        ~ClientHandler();


        void start(); // Accept the handshake.
        void handleHandshake(boost::system::error_code ec);

        void receiveMessageAsync();

        void sendMessage(const std::string &message); // SEND MESSAGE TO SERVER






};


#endif //CLIENTHANDLER_H
