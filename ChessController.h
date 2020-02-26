//
// Created by jordan on 2/12/20.
//

#ifndef CHESSV2_CHESSCONTROLLER_H
#define CHESSV2_CHESSCONTROLLER_H


#include "Pieces/ChessBoard.h"

/* Takes input from the user and passes it to the board. */
class ChessController {


public:
    void playGame();



private:
    ChessBoard chessBoard;


    bool validateInput(std::string &input); //Returns true if input was valid.
    bool convertChessCoordinate(ChessCoordinate &a, ChessCoordinate &b, std::string input);



};






#endif //CHESSV2_CHESSCONTROLLER_H
