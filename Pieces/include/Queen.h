//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_QUEEN_H
#define CHESSV2_QUEEN_H

#include "Piece.h"

class Queen : public Piece{
    Queen(Color color, char16_t symbol);
    void print() override;
    bool isValidMove() override ;
};


#endif //CHESSV2_QUEEN_H
