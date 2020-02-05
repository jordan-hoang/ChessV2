//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_KING_H
#define CHESSV2_KING_H


#include "Piece.h"

class King : public Piece {
private:
    bool can_castle;
public:
    bool canCastle();
    King(Color color, char16_t symbol);

    bool isValidMove() override ;
    void print() override ;


};

#endif //CHESSV2_KING_H
