//
// Created by jordan on 2/4/20.
//

#include <ChessCollision.h>
#include "Rook.h"


Rook::Rook(Color color, char16_t symbol) : Piece{color, symbol} { }

bool Rook::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    if(a.row == b.row || a.col == b.col){
        return ChessCollision::isPathClear(a,b, chess_board_ );
    }
    return false;
}
void Rook::print() {
    std::cout << "I'm a rook\n";
}