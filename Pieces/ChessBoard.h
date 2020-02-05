//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_CHESSBOARD_H
#define CHESSV2_CHESSBOARD_H

#include <memory>
#include <vector>
#include "Piece.h"

typedef std::unique_ptr<Piece> row;
typedef std::vector<std::unique_ptr<Piece>> R;


class ChessBoard {
private:
    std::vector<R> chessboard_;
public:
    ChessBoard();
    void printChessBoard() const;




};


#endif //CHESSV2_CHESSBOARD_H
