//
// Created by jordan on 2/12/20.
//

#ifndef CHESSV2_CHESSCONTROLLER_H
#define CHESSV2_CHESSCONTROLLER_H

#include <thread>
#include "ChessCoordinate.h"
#include "ChessBoard.h"

#include "ChessNetwork.h"
#include "INetworkMessageListener.h"


/* Takes input from the user and passes it to the board. */
class ChessController : public INetworkMessageListener, public std::enable_shared_from_this<ChessController>  {


public:

    ChessController();

    // Runs the thread
    void run(){
        chessNetwork_->initNetworkListener(weak_from_this());
        _chessThread = std::thread(&ChessController::threadMain, this);
    }
    void wait();

    // Technically these 2 functions should be private to avoid exposing them, but we need public for testing.
    // That or you can just mock objects but too much work.
    bool validChessStringInput(std::string &input); //Returns true if input was valid.
    std::pair<ChessCoordinate, ChessCoordinate> convertChessCoordinate(std::string input, bool &valid);
    std::string onClientMessageReceived(const std::string& chessMove, const std::string &client_color) override; // A function we pass to chessNetwork

    ~ChessController();

private:
    ChessBoard chessBoard;
    std::thread _chessThread;
    std::shared_ptr<ChessNetwork> chessNetwork_;

    void asyncSendToClient();

    void threadMain();
    void playGame();

};


#endif //CHESSV2_CHESSCONTROLLER_H
