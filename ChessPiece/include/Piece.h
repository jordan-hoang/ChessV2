//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_PIECE_H
#define CHESSV2_PIECE_H


#include <cwctype>
#include <iostream>
#include "ChessBoard.h"
#include "ChessCoordinate.h"

class ChessBoard;



enum class Color {
    WHITE, BLACK, NO_COLOR
};


inline std::ostream& operator<<(std::ostream& os, Color color) {
    switch (color) {
        case Color::WHITE:   return os << "WHITE";
        case Color::BLACK:   return os << "BLACK";
        case Color::NO_COLOR: return os << "NO_COLOR";
        default:             return os << "UNKNOWN_COLOR";
    }
}




class Piece {
private:
    char16_t chara_;
    Color  chessColor;
protected:
    Piece(Color color, char16_t symbol);
public:
    virtual ~Piece() = default;

    virtual bool movePiece(ChessCoordinate a, ChessCoordinate b, ChessBoard &chess_board_) = 0;
    virtual void print() = 0;
    wchar_t getSymbol();
    Color getColor();
};



// Why down here???




#endif //CHESSV2_PIECE_H
