//
// Created by jordan on 2/4/20.
//

#include "Knight.h"

Knight::Knight(Color color, char16_t symbol) : Piece{color, symbol}{

}

bool Knight::movePiece(ChessCoordinate a, ChessCoordinate b) {
    return true;
}

void Knight::print() {
    std::cout << "I am a knight";
}