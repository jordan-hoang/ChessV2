//
// Created by jordan on 2/4/20.
//

#include <Piece.h>

#include "ChessBoard.h"


ChessBoard::ChessBoard() {
    for(int i = 0; i < 8; i++){
        std::vector<std::unique_ptr<Piece>> row;
        for(int j = 0; j < 8; j++){

            auto a = std::make_unique<NullPiece>();
            row.push_back(std::move(a));
        }
        chessboard_.push_back(std::move(row));
    }
}

void ChessBoard::printChessBoard() const {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            chessboard_[i][j]->print();
        }
    }
}