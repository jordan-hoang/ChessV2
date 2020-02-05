//
// Created by jordan on 2/4/20.
//

#include "King.h"

King::King(Color color, char16_t symbol) :
        Piece{color, symbol}, can_castle{true} {};

bool King::movePiece(ChessCoordinate a, ChessCoordinate b) {
    return true;
}


bool King::canCastle() {
    return can_castle;
}

void King::print() {
    std::cout << "I am a king!\n";
}