//
// Created by jordan on 2/4/20.
//

#include "Knight.h"
#include <algorithm>

Knight::Knight(Color color, char16_t symbol) : Piece{color, symbol}{

}

bool Knight::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    Color friendly_color = chess_board_.getPiece(a)->getColor();    
    Color enemyColor = chess_board_.getPiece(b)->getColor();
    // You are attaking yourself which is an illegal move
    if(friendly_color == enemyColor){
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
    return (rst != possibleMoves.end());
}

void Knight::print() {
    std::cout << "I am a knight";
}