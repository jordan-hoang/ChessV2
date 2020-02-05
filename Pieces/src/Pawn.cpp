//
// Created by jordan on 2/4/20.
//

#include "Pawn.h"

Pawn::Pawn(Color color, char16_t symbol) : Piece{color, symbol}, canDoubleJump{true}{

}


void Pawn::print() {
    std::cout << "I am a pawn\n";
}

bool Pawn::movePiece(ChessCoordinate from_spot, ChessCoordinate to_spot, const ChessBoard &chess_board_) {
    return true;
}
