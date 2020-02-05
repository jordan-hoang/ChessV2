//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_PIECE_H
#define CHESSV2_PIECE_H


#include <cwctype>
#include <iostream>
#include "../ChessBoard.h"



enum class Color {
    WHITE, BLACK, NO_COLOR
};

//Imported from ChessV1
struct ChessCoordinate {
    int row;
    int col;

    bool operator==(const ChessCoordinate a) const {
        return ( row == a.row  && col == a.col );
    }
    ChessCoordinate operator+(const ChessCoordinate &b) const {
        return ChessCoordinate{row + b.row, col + b.col};
    }
    ChessCoordinate operator-(const ChessCoordinate &b) const {
        return ChessCoordinate{row - b.row, col - b.col};
    }
    ChessCoordinate& operator++(){
        row++;
        col++;
        return *this;
    }
    ChessCoordinate toOne(){
        ChessCoordinate rst = *this;
        if(rst.row == 0){
            rst.row = 0;
        } else{
            rst.row = 1;
        }
        if(rst.col == 0){
            rst.col = 0;
        } else{
            rst.col = 1;
        }
        return rst;
    }
    ChessCoordinate& operator=(const ChessCoordinate &copy){
        row = copy.row;
        col = copy.col;
        return *this;
    }
    bool isValid() const{
        if(row < 0 || row >= 8){
            return false;
        }
        return !(col < 0 || col >= 8 );
    }
    friend std::ostream &operator<<(std::ostream &os, const ChessCoordinate &coordinate) {
        os << "{"  << coordinate.row << ", " << coordinate.col << "}";
        return os;
    }
    ChessCoordinate() : row(-1), col(-1){}
    ChessCoordinate(int enteredRow, int enteredCol) : row(enteredRow), col(enteredCol) {}
};


class Piece {
private:
    char16_t chara_;
    Color  chessColor;
protected:
    Piece(Color color, char16_t symbol);
public:
    virtual bool movePiece(ChessCoordinate from_spot, ChessCoordinate to_spot, const ChessBoard &chess_board_) = 0;
    virtual void print() = 0;
    wchar_t getSymbol();
    Color getColor();
};


///Include subclasses here
#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "NullPiece.h"

#endif //CHESSV2_PIECE_H
