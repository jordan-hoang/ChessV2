//
// Created by jordan on 2/4/20.
//

#include "Bishop.h"
#include "ChessCollision.h"

Bishop::Bishop(Color color, char16_t symbol) :
        Piece{color, symbol} {};


bool Bishop::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    auto friend_color = chess_board_.getPiece(a)->getColor();
    auto enemy_colr = chess_board_.getPiece(b)->getColor();

    if(friend_color == enemy_colr){
        return false;
    }

    //We need code to check if it is 'diagonal'
    int diffRow = abs( b.row - a.row);
    int diffCol = abs( b.col - a.col);

    return ( diffRow == diffCol && ChessCollision::isPathClear(a,b,chess_board_) );    
}

void Bishop::print() {
    std::cout << "I am a bishop!\n";
}