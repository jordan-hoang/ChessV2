//
// Created by jordan on 2/4/20.
//

// A class that represents an empty space on a chessBoard,
#include "NullPiece.h"

NullPiece::NullPiece(Color color, char16_t symbol) : Piece{color, symbol}{}

void NullPiece::print() {
}

bool NullPiece::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    return false;
}
