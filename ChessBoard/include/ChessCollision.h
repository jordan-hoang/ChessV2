//
// Created by jordan on 2/27/20.
//

#ifndef CHESSV2_CHESSCOLLISION_H
#define CHESSV2_CHESSCOLLISION_H


#include "ChessCoordinate.h"
#include "ChessBoard.h"
#include "Piece.h"

/** A helper class that checks to see if the paths are clear.
 *  Doesn't necessary need to be a helper class, putting this in as a static class that
 *  belongs to Piece is all you really need since only Chess Pieces will really need this class.
 */
class ChessCollision final {
    private:
        static bool isVerticalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
        static bool isHorizontalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
        static bool isDiagonalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
    public:
        static bool isPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b);
        ChessCollision() = delete;
        ChessCollision(const ChessCollision&) = delete;
        ChessCollision& operator=(const ChessCollision&) = delete;
};


#endif //CHESSV2_CHESSCOLLISION_H
