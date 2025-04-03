#pragma once
#include <string>

class ClientHandler; // Forward declaration

class IClientEvents {
public:
    virtual ~IClientEvents() = default;
    
    // Client → Network notifications
    virtual void onDisconnect(std::shared_ptr<ClientHandler> client) = 0;
    
    // Network → Client broadcasting
    virtual void broadcastToAll(const std::string& message) = 0;
};