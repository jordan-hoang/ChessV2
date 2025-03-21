//
// Created by jordan on 2/12/20.
//

#ifndef CHESSV2_CHESSCONTROLLER_H
#define CHESSV2_CHESSCONTROLLER_H

#include <thread>
#include "ChessCoordinate.h"
#include "ChessBoard.h"

#include "ChessNetwork.h"


/* Takes input from the user and passes it to the board. */
class ChessController {


public:

    // Runs the thread
    void run(){
        _chessThread = std::thread(&ChessController::threadMain, this);
    }

    void wait();

    // Technically these 2 functions should be private to avoid exposing them, but we need public for testing.
    // That or you can just mock objects but too much work.
    bool validChessStringInput(std::string &input); //Returns true if input was valid.
    std::pair<ChessCoordinate, ChessCoordinate> convertChessCoordinate(std::string input, bool &valid);

    ~ChessController();

private:
    ChessBoard chessBoard;
    std::thread _chessThread;
    ChessNetwork myNetwork;


    void threadMain();
    void playGame();


};


#endif //CHESSV2_CHESSCONTROLLER_H
