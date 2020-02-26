
// Created by jordan on 2/26/20.

#include "ChessCoordinate.h"
#include <gtest/gtest.h>
#include <NullPiece.h>
#include "gmock/gmock.h"
#include "../Pieces/ChessBoard.h"


bool pieceMoved(ChessBoard &board, ChessCoordinate a, ChessCoordinate b){

    bool val = board.executeMove(a,b);

    Piece *const mo = board.getPiece(a);
    Piece *f = dynamic_cast<NullPiece*>(mo);  //For testing purposes.

    if(f == nullptr){
        std::cout << "Wow!\n";
    }

    return val;

}


TEST(BoardTest, pawn){

    ChessBoard board;
    ChessCoordinate a{6,1};
    ChessCoordinate b{5,1};
    bool val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";


    a.set(1,1);
    b.set(3,1);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when executing double jump!";


    a.set(6,0);
    b.set(4,0);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when executing double jump!";



    board.printChessBoard();
}