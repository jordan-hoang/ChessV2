//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_KNIGHT_H
#define CHESSV2_KNIGHT_H

#include "Piece.h"

//Overload its move
class Knight : public Piece {

public:
    Knight(Color color, char16_t symbol);
    bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) override;
    void print() override;
};


#endif //CHESSV2_KNIGHT_H
