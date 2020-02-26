//
// Created by jordan on 2/4/20.
//

#include "Rook.h"


Rook::Rook(Color color, char16_t symbol) : Piece{color, symbol} { }

bool Rook::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    return true;
}
void Rook::print() {
    std::cout << "I'm a rook\n";
}