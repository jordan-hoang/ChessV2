//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_KING_H
#define CHESSV2_KING_H

#include <algorithm>
#include "Piece.h"

class King : public Piece {
private:
    bool can_castle;
public:
    bool canCastle();
    King(Color color, char16_t symbol);

    bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) override ;
    void print() override ;


};

#endif //CHESSV2_KING_H
