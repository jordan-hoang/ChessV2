//
// Created by jordan on 2/12/20.
//

#ifndef CHESSV2_CHESSCONTROLLER_H
#define CHESSV2_CHESSCONTROLLER_H

#include "ChessCoordinate.h"
#include "ChessBoard.h"

/* Takes input from the user and passes it to the board. */
class ChessController {


public:
    void playGame();
    bool validChessStringInput(std::string &input); //Returns true if input was valid.
    std::pair<ChessCoordinate, ChessCoordinate> convertChessCoordinate(std::string input, bool &valid);
private:
    ChessBoard chessBoard;

};






#endif //CHESSV2_CHESSCONTROLLER_H
