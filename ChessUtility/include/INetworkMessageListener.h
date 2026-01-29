//
// Created by jorda on 1/28/2026.
//

#ifndef INETWORKMESSAGELISTENER_H
#define INETWORKMESSAGELISTENER_H
#include <string>


class INetworkMessageListener {
public:

    virtual std::string onClientMessageReceived(const std::string& chessMove, const std::string &client_color) = 0; // A function we pass to chessNetwork
    INetworkMessageListener() = default;
    virtual ~INetworkMessageListener() = default;
};



#endif //INETWORKMESSAGELISTENER_H
