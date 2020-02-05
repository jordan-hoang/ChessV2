//
// Created by jordan on 2/4/20.
//

#include "Pawn.h"

Pawn::Pawn(Color color, char16_t symbol) : Piece{color, symbol}, canDoubleJump{true}{

}


void Pawn::print() {
    std::cout << "I am a pawn\n";
}

bool Pawn::movePiece(ChessCoordinate a, ChessCoordinate b, const ChessBoard &chess_board_) {
    //First we gotta grab the color.

    auto &board = chess_board_.getChessboard();

    int dirTravel = (this->getColor() == Color::WHITE) ? 1 : -1;
    ChessCoordinate c = b - a;

    if(c.row == dirTravel && c.col == 0 ){
        return true; //As long as there isn't an enemy there.
    }



    return false;
}

