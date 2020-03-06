//
// Created by jordan on 2/4/20.
//

#include "Bishop.h"
#include "ChessCollision.h"

Bishop::Bishop(Color color, char16_t symbol) :
        Piece{color, symbol} {};


bool Bishop::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    //We need code to check if it is 'diagonal'
    int diffRow = abs( b.row - a.row);
    int diffCol = abs( b.col - a.col);


    if( diffRow == diffCol ){
        if(ChessCollision::isPathClear(a,b, chess_board_) ){
            return true;
        }
    }






    return false;
}

void Bishop::print() {
    std::cout << "I am a bishop!\n";
}