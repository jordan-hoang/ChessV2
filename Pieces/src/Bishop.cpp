//
// Created by jordan on 2/4/20.
//

#include "Bishop.h"

Bishop::Bishop(bool isWhite, wchar_t symbol) :
        Piece{isWhite, symbol} {};


bool Bishop::isValidMove() {
    return true;
}

void Bishop::print() {
    std::cout << "I am a bishop!\n";
}