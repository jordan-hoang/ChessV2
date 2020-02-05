//
// Created by jordan on 2/4/20.
//

#include "Queen.h"

Queen::Queen(Color color, char16_t symbol) : Piece{color, symbol}{

}

bool Queen::isValidMove() {
    return true;
}

void Queen::print(){
    std::cout << "I'm a queen\n";
}
