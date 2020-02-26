//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_PAWN_H
#define CHESSV2_PAWN_H

#include "Piece.h"

class Pawn : public Piece{
private:
    bool canDoubleJump;
public:
    Pawn(Color color, char16_t symbol);
    void print() override ;
    bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) override;



};


#endif //CHESSV2_PAWN_H
