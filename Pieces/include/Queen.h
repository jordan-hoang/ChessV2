//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_QUEEN_H
#define CHESSV2_QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    Queen(Color color, char16_t symbol);
    void print() override;
    bool movePiece(ChessCoordinate from_spot, ChessCoordinate to_spot, const ChessBoard &chess_board_) override ;
};


#endif //CHESSV2_QUEEN_H
