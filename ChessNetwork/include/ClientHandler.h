
#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <memory>
#include <optional>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket/stream.hpp>
#include "IClientEvents.h"

using namespace boost::asio;



class ChessNetwork; // Forward declare so it know this exists.


struct ClientInfo {
    uint32_t id = 0;                 // Unique client identifier
    std::string color;               // "white" or "black" or "spectator"
    // bool authenticated = false;      // Future auth support ???
    // std::string endpoint = "UNUSED";
};

/**
* Represents a single client for the chess project.
*/
class ClientHandler : public std::enable_shared_from_this<ClientHandler>
{
    private:
        std::optional<boost::beast::websocket::stream<boost::asio::ip::tcp::socket>> websocket_;
        std::function<std::string(const std::string&, const std::string&)> onMessageReceived_callback; // The call back function
        std::weak_ptr<IClientEvents> events_; // Changed to interface pointer?!!!
        boost::asio::strand<any_io_executor> strand_;

    public:
        ClientInfo client_info;
        ClientHandler(ip::tcp::socket socket,
                      std::function<std::string(const std::string&, const std::string&)> callBack,
                      std::weak_ptr<IClientEvents> events,
                      strand<boost::asio::any_io_executor> strand
                      );


        ~ClientHandler();

        void start(std::function<void()> onHandshakeComplete = nullptr);


        void handleHandshake(boost::system::error_code ec);
        void receiveMessageAsync();
        void sendMessage(const std::string &message); // SEND MESSAGE TO SERVER



};


#endif //CLIENTHANDLER_H
