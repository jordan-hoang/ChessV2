
// Created by jordan on 2/26/20.

#include "ChessCoordinate.h"
#include <gtest/gtest.h>
#include <NullPiece.h>
#include "gmock/gmock.h"
#include "../ChessBoard/include/ChessBoard.h"


bool pieceMoved(ChessBoard &board, ChessCoordinate a, ChessCoordinate b){
    bool val = board.executeMove(a,b);
    Piece *const mo = board.getPiece(a);
    Piece *f = dynamic_cast<NullPiece*>(mo);  //For testing purposes.

    if(f == nullptr){
       val = false;
    }
    return val;
    return true;
}

/*
TEST(BoardTest, pawnForward){
    bool val;

    ChessBoard board;
    ChessCoordinate a{6,1};
    ChessCoordinate b{5,1};
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";


    a.set(1,7);
    b.set(2,7);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";


    a.set(5,1);
    b.set(4,1);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";

    a.set(2,7);
    b.set(3,7);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";

    a.set(6,6);
    b.set(4,6);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";

    a.set(3,7);
    b.set(4,6);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";

    //board.printChessBoard();
}

*/
TEST(BoardTest, pawn){

    ChessBoard board;
    ChessCoordinate a{6,1};
    ChessCoordinate b{5,1};
    bool val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when moving pawn up 1 square";

/*
    a.set(1,1);
    b.set(3,1);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when executing double jump!";


    //White Move
    a.set(6,2);
    b.set(4,2);
    val = pieceMoved(board,a,b); //Checks to see if the piece moved
    EXPECT_EQ(val, true) << "Error when executing double jump!";


    //Black move
    a.set(4,1);
    b.set(5,1);
    val = pieceMoved(board,a,b);
    EXPECT_EQ(val, false);

*/
}