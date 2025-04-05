//
// Created by jordan on 2/4/20.
//

#include "Queen.h"
#include <ChessCollision.h>

Queen::Queen(Color color, char16_t symbol) : Piece{color, symbol}{

}

bool Queen::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    int diffRow = abs( b.row - a.row);
    int diffCol = abs( b.col - a.col);

    auto friend_color = chess_board_.getPiece(a)->getColor();
    auto enemy_colr = chess_board_.getPiece(b)->getColor();

    if(friend_color == enemy_colr){
        return false;
    }

    if(diffCol == diffRow || a.row == b.row || a.col == b.col){
        return ChessCollision::isPathClear(a,b, chess_board_);
    }
    return false;
}

void Queen::print(){
    std::cout << "I'm a queen\n";
}
