//
// Created by jordan on 2/12/20.
//

#include "ChessCoordinate.h"


ChessCoordinate ChessCoordinate::set(int row, int col) {
    this->row = row;
    this->col = col;
    return *this;
}

bool ChessCoordinate::isValid() const {
    if(row < 0 || row >= 8){
        return false;
    }
    return !(col < 0 || col >= 8 );
}