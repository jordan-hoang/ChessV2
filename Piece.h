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

public:
        virtual bool isValidMove() = 0;

        Piece(bool isWhite, wchar_t symbol) : is_white{isWhite} {
        }


        wchar_t getSymbol(){
            return chara_;
        }
        virtual void print(){
            std::cout << "I am a piece!\n";
        }

};


class King : public Piece {
    private:
        bool can_castle;
    public:
        bool getCastle();
        King(bool isWhite, wchar_t symbol) :
            Piece{isWhite, symbol}, can_castle{true} {};

        bool isValidMove(){
            return true;
        }
        void print() override {
            std::cout << "I am a king!\n";
        }


};

class Bishop : public Piece {

public:
    Bishop(bool isWhite, wchar_t symbol) :
            Piece{isWhite, symbol} {};

    bool isValidMove() override {
        return true;
    }
    void print() override {
        std::cout << "I am a bishop!\n";
    }


};




#endif //CHESSV2_PIECE_H
