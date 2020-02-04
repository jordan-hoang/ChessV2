//
// Created by jordan on 2/4/20.
//

#include "Piece.h"



wchar_t Piece::getSymbol(){
    return chara_;
}

void Piece::print(){
    std::cout << "I am a piece!\n";
}

Piece::Piece(bool isWhite, wchar_t symbol) : is_white{isWhite} {
}

bool Piece::isWhite() {
    return is_white;
}

