//
// Created by jordan on 2/4/20.
//

#include "Piece.h"
#include <memory>


wchar_t Piece::getSymbol(){
    return chara_;
}

void Piece::print(){
    std::cout << "I am a piece!\n";
}

Piece::Piece(Color color, char16_t symbol) : chessColor{color}, chara_{symbol} {
}

Color Piece::getColor() {
    return chessColor;
}


