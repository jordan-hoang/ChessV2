//
// Created by jordan on 2/4/20.
//

#include "King.h"

King::King(bool isWhite, wchar_t symbol) :
        Piece{isWhite, symbol}, can_castle{true} {};

bool King::isValidMove(){
    return true;
}


bool King::canCastle() {
    return canCastle();
}

void King::print() {
    std::cout << "I am a king!\n";
}