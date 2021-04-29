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

bool Pawn::diagonalMove(ChessCoordinate start, ChessCoordinate finish, ChessBoard &chess_board_){

    Color friendly_color = this->getColor();
    Color enemy_color = chess_board_.getPiece(finish)->getColor();
    ////////////////////////////////////////////
    std::array<ChessCoordinate, 2> a;
    if(friendly_color == Color::WHITE) {
        a[0] = {-1, 1};
        a[1] = {-1, -1};
    } else if (friendly_color == Color::BLACK){
        a[0] = {1, 1};
        a[1] = {1, -1};
    } else{
        exit(-1);
    }
    ChessCoordinate rst = finish - start;
    return ( std::find(a.begin(), a.end(), rst) != a.end() );
}


bool Pawn::movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) {
    //First we gotta grab the color.
    //+ means goes up -1 means goes down the chess board

    int directionTravel = (this->getColor() == Color::BLACK) ? 1 : -1;
    int difY = b.row - a.row;
    int difX = b.col - a.col;


    Color target = chess_board_.getPiece(b)->getColor();

    //A pawn can travel at most 1 unit diagonally therefore there xPos,yPos must have changed by 1.
    bool result = diagonalMove(a, b, chess_board_);

    // Code for double jump.
    if(target == Color::NO_COLOR){
        if (a.row + directionTravel == b.row && (difX == 0 || difY == 0 ) ) {
            result =  true; // generic code for both.
        } else if (a.row == 1 && directionTravel == 1 &&
                   (a.row + directionTravel * 2) == b.row) {
            result = true;
        } else if (a.row == 6 && directionTravel == -1 &&
                   (a.row + directionTravel * 2) == b.row) {
            result = true;
        }
    }

    return result;

}

