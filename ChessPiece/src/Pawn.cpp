//
// Created by jordan on 2/4/20.
//

#include "Pawn.h"
#include <algorithm>
#include <array>

Pawn::Pawn(Color color, char16_t symbol) : Piece{color, symbol}, canDoubleJump{true}{

}


void Pawn::print() {
    std::cout << "I am a pawn\n";
}

// What does this do.... I don't remember anymore
bool Pawn::diagonalMove(ChessCoordinate start, ChessCoordinate finish, ChessBoard &chess_board_){

    Color friendly_color = this->getColor();
    Color enemy_color = chess_board_.getPiece(finish)->getColor();

    // Can't move diagonally onto your pieces or null_pieces. Only enemy pieces are allowed.
    if(friendly_color == enemy_color || enemy_color == Color::NO_COLOR) {
        return false;
    }


    /// Array of all possible diagonal moves a pawn can go to.
    std::array<ChessCoordinate, 2> a;
    if(friendly_color == Color::WHITE) {            /// Down the array if white.
        a[0] = {-1, 1};
        a[1] = {-1, -1};
    } else if (friendly_color == Color::BLACK){    /// Up the array if black.
        a[0] = {1, 1};
        a[1] = {1, -1};
    } else{
        exit(-1);
    }

    // Can simplify this.
    if(finish == start + a[0] || finish == start + a[1]) {
        return true;
    }
    return false;
}

/**
 * Checks the absolute distance you are moving by, if it's >= 3 than it's not valid for pawns.
 * At most pawns can only move 2 squares
 * @param difX
 * @param difY
 * @return
 */
bool isValidNum(int difX, int difY) {
    return abs(difX) + abs(difY) < 3;
}

bool Pawn::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    //First we gotta grab the color.
    //+ means goes up -1 means goes down the chess board

    int directionTravel = (this->getColor() == Color::BLACK) ? 1 : -1;
    int difY = b.row - a.row;
    int difX = b.col - a.col;


    Color target = chess_board_.getPiece(b)->getColor();
    bool result = diagonalMove(a, b, chess_board_);

    // Code for double jump.
    if(target == Color::NO_COLOR){
        if (a.row + directionTravel == b.row && (difX == 0 || difY == 0 ) ) {
            result =  true; // generic code for both.
        } else if (a.row == 1 && directionTravel == 1 &&
                   (a.row + directionTravel * 2) == b.row && abs(difX) == 0) {
            result = true;
        } else if (a.row == 6 && directionTravel == -1 &&
                   (a.row + directionTravel * 2) == b.row && abs(difX) == 0) {
            result = true;
        }

    }

    return result;

}

