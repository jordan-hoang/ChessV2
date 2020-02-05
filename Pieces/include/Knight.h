//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_KNIGHT_H
#define CHESSV2_KNIGHT_H

#include "Piece.h"

//Overload its move
class Knight : public Piece {
    Knight(Color color, char16_t symbol);
    bool isValidMove() override;

    void print() override;
};


#endif //CHESSV2_KNIGHT_H
