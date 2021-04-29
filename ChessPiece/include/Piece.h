//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_PIECE_H
#define CHESSV2_PIECE_H


#include <cwctype>
#include <iostream>


class ChessBoard;
#include "../../ChessBoard/include/ChessBoard.h"
#include "../../ChessUtility/include/ChessCoordinate.h"

enum class Color {
    WHITE, BLACK, NO_COLOR
};

//Imported from ChessV1


class Piece {
private:
    char16_t chara_;
    Color  chessColor;
protected:
    Piece(Color color, char16_t symbol);
public:
    virtual bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) = 0;
    virtual void print() = 0;
    wchar_t getSymbol();
    Color getColor();

};



// Why down here???




#endif //CHESSV2_PIECE_H
