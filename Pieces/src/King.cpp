//
// Created by jordan on 2/4/20.
//

#include "King.h"

King::King(Color color, char16_t symbol) :
        Piece{color, symbol}, can_castle{true} {};

/**
 * Moves a King to coordinate b given that the spot is not occupied with friendly. 
 * Checks, and castling not implemented yet
 */
bool King::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {

    Color friendly_color = chess_board_.getPiece(a)->getColor();    
    Color enemyColor = chess_board_.getPiece(b)->getColor();

    //You are attaking yourself which is an illegal move.
    if(friendly_color == enemyColor){
        return false;
    }

    //all possible moves a king piece can make.
        std::vector<ChessCoordinate> possibleMoves = {
            {a.row, a.col + 1},
            {a.row, a.col - 1},

            {a.row + 1, a.col + 1},
            {a.row + 1, a.col - 1},
            {a.row + 1, a.col},

            {a.row - 1, a.col + 1},
            {a.row - 1, a.col - 1},
            {a.row - 1, a.col},
    };

    auto found = std::find(possibleMoves.begin(), possibleMoves.end(), b); 
    if(found != possibleMoves.end()){
        can_castle = false;
        return true;
    }
    return false;
}

bool King::canCastle() {
    return can_castle;
}

void King::print() {
    std::cout << "I am a king!\n";
}