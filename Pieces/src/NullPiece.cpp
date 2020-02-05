//
// Created by jordan on 2/4/20.
//

#include "NullPiece.h"


NullPiece::NullPiece(Color color, char16_t symbol) : Piece{color, symbol}{
}


void NullPiece::print() {
    std::cout << "I'm a nullpiece";
}
bool NullPiece::movePiece(ChessCoordinate from_spot, ChessCoordinate to_spot, const ChessBoard &chess_board_) {
    return false;
}
