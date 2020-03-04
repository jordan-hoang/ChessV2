//
// Created by jordan on 2/4/20.
//

#include "Bishop.h"
#include "ChessCollision.h"

Bishop::Bishop(Color color, char16_t symbol) :
        Piece{color, symbol} {};


bool Bishop::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    if(ChessCollision::isPathClear(a,b,chess_board_) ){
        chess_board_.movePiece(a,b);
        return true;
    }




    return false;
}

void Bishop::print() {
    std::cout << "I am a bishop!\n";
}