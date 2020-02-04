//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_PIECE_H
#define CHESSV2_PIECE_H


#include <cwctype>
#include <iostream>


class Piece {
private:
    wchar_t chara_;
    bool  is_white;

protected:
    Piece(bool isWhite, wchar_t symbol);
public:
    virtual bool isValidMove() = 0;
    virtual void print() = 0;
    wchar_t getSymbol();
    bool isWhite();
};








#endif //CHESSV2_PIECE_H
