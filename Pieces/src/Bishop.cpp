//
// Created by jordan on 2/4/20.
//

#include "Bishop.h"

Bishop::Bishop(Color color, char16_t symbol) :
        Piece{color, symbol} {};


bool Bishop::movePiece(ChessCoordinate a, ChessCoordinate b) {
    return true;
}

void Bishop::print() {
    std::cout << "I am a bishop!\n";
}