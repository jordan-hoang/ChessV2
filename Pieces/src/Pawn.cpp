//
// Created by jordan on 2/4/20.
//

#include "Pawn.h"

Pawn::Pawn(Color color, char16_t symbol) : Piece{color, symbol}, canDoubleJump{true}{

}


void Pawn::print() {
    std::cout << "I am a pawn\n";
}

bool Pawn::movePiece(ChessCoordinate start, ChessCoordinate finish, ChessBoard &chess_board_) {
    //First we gotta grab the color.
    //+ means goes up -1 means goes down the chess board

    int directionTravel = (this->getColor() == Color::BLACK) ? 1 : -1;

    int difY = finish.row - start.row;
    int difX = finish.col - start.col;

    //Works if the path is clear

    // Handling diagonal movement, should be invalid if travelling backwards though
    int diffX  = abs(finish.row - start.row);
    int diffY  = abs(finish.col - start.col);

    Color target = chess_board_.getPiece(finish)->getColor();

    //A pawn can travel at most 1 unit diagonally therefore there xPos,yPos must have changed by 1.
    if(diffX == 1 && diffY == 1){
        if(start.row + directionTravel == finish.row && target == Color::NO_COLOR) {
            chess_board_.movePiece(start,finish);
            return true;
        } else if(start.row + directionTravel == finish.row){
            chess_board_.movePiece(start,finish);
            return true;
        }
    }

    if(target == Color::NO_COLOR){
        if (start.row + directionTravel == finish.row && ( difX == 0 || difY == 0 ) ) {
            chess_board_.movePiece(start,finish);
            return true; // generic code for both.
        } else if (start.row == 1 && directionTravel == 1 && (start.row + directionTravel * 2) == finish.row) {
            chess_board_.movePiece(start,finish);
            return true; //::VALID_MOVE; //CODE FOR WHITE
        } else if (start.row == 6 && directionTravel == -1 && (start.row + directionTravel * 2) == finish.row) {
            chess_board_.movePiece(start,finish);
            return true; //::VALID_MOVE; //CODE FOR BLACK
        }
    }


    return false;

}

