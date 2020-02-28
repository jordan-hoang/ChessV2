//
// Created by jordan on 2/27/20.
//

#ifndef CHESSV2_CHESSCOLLISION_H
#define CHESSV2_CHESSCOLLISION_H


#include "ChessCoordinate.h"
#include "ChessBoard.h"
#include "Piece.h"


class ChessCollision {
    public:
        static bool isVerticalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
        static bool isHorizontalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
        static bool isDiagonalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);

};


#endif //CHESSV2_CHESSCOLLISION_H
