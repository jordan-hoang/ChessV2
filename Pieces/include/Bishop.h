//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_BISHOP_H
#define CHESSV2_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {

public:
    Bishop(Color color, char16_t symbol);
    bool movePiece(ChessCoordinate a, ChessCoordinate b, const ChessBoard &chess_board_) override;
    void print() override;
};



#endif //CHESSV2_BISHOP_H
