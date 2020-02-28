//
// Created by jordan on 2/4/20.
//

#include "Knight.h"
#include <algorithm>

Knight::Knight(Color color, char16_t symbol) : Piece{color, symbol}{

}

bool Knight::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    if(chess_board_.getPiece(b)->getColor() != Color::NO_COLOR){
        return false;
    }

    std::vector<ChessCoordinate> possibleMoves = {
            {a.row + 2, a.col + 1},
            {a.row + 2, a.col - 1},

            {a.row - 2, a.col + 1},
            {a.row - 2, a.col - 1},

            {a.row + 1, a.col + 2},
            {a.row + 1, a.col - 2},

            {a.row - 1, a.col + 2},
            {a.row - 1, a.col - 2},
    };

    auto rst = std::find(possibleMoves.begin(), possibleMoves.end(), b);
    if(rst != possibleMoves.end()){
        chess_board_.movePiece(a,b);
        return true;
    }
    return false;
}

void Knight::print() {
    std::cout << "I am a knight";
}