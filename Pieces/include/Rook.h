//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_ROOK_H
#define CHESSV2_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    Rook(Color color, char16_t symbol);
    void print() override;
    bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) override;




};


#endif //CHESSV2_ROOK_H
