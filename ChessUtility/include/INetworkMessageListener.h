//


#pragma once
#include <string>

/**
 * Interface class, instead of directly passing down ChessController to ChessNetwork, we make ChessController implement this interface,
 * and then have ChessNetwork accept this interface.
 */
class INetworkMessageListener {
public:

    virtual std::string onClientMessageReceived(const std::string& chessMove, const std::string &client_color) = 0; // A function we pass to chessNetwork
    INetworkMessageListener() = default;
    virtual ~INetworkMessageListener() = default;
};



