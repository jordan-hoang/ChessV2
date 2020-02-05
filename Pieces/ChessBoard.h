//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_CHESSBOARD_H
#define CHESSV2_CHESSBOARD_H

#include <memory>
#include <vector>
#include "Piece.h"

typedef std::unique_ptr<Piece> smart_piece;
typedef std::vector<std::unique_ptr<Piece>> smartRow;


class ChessBoard {
private:
    std::vector<smartRow> chessboard_;
    const Piece * whiteKing;   // White king in this case refers to the king that would go first.
    const Piece * blackKing;   // Black king in this case refers to the king that would go second.
    bool isWhiteTurn;


    smartRow genBackRank(Color c);

public:
    ChessBoard();
    void printChessBoard() const;



};


#endif //CHESSV2_CHESSBOARD_H
