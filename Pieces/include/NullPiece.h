//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_NULLPIECE_H
#define CHESSV2_NULLPIECE_H


#include "Piece.h"

class NullPiece : public Piece{
public:
    explicit NullPiece(Color color = Color::NO_COLOR, char16_t symbol=' ');
    void print() override ;
    bool isValidMove() override ;
};


#endif //CHESSV2_NULLPIECE_H
