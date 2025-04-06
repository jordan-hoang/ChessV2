
// Created by jordan on 2/26/20.

#include "../ChessUtility/include/ChessCoordinate.h"
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
}


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

}

TEST(BoardTestMoves, pawn){

    ChessBoard board;

    ChessCoordinate a{6,7};
    ChessCoordinate b{4,6};
    bool val = pieceMoved(board,a,b); //Checks to see if the piece moved
    //board.printChessBoard();
    EXPECT_EQ(val, false) << "Error ILLEGAL move, moving like a knight is somehow valid.";

}


TEST(BoardTest, pawnDiagonal){

    ChessBoard board;
    bool result;

    //std::string moveFrom = "a2";
    //std::string moveTo = "a4";

    ChessCoordinate moveFrom = ChessCoordinate{6,0};   // a2
    ChessCoordinate moveTo   = ChessCoordinate{4,0};   // a4

    result = board.executeMove(moveFrom, moveTo);
    EXPECT_EQ(result, true) << "Was not able to move the pawn 2 squares up.";
    //board.printChessBoard();

    moveFrom = ChessCoordinate{1,1}; // b7
    moveTo = ChessCoordinate{3,1}; // b5
    result = board.executeMove(moveFrom, moveTo);
    EXPECT_EQ(result, true) << "";

    //board.printChessBoard();
    // //See if red can kill blue diagonally.
    moveFrom = ChessCoordinate{4,0};    //a4
    moveTo = ChessCoordinate{3,1}; //b5
    result = board.executeMove(moveFrom, moveTo);
    EXPECT_EQ(result, true) << "";
    //board.printChessBoard();


    //
    // moveFrom = "a7";
    // moveTo = "a6";
    // board.executeMove(moveFrom, moveTo);
    //
    // //move.getBoardView();
    //
    // moveFrom = "b5";
    // moveTo = "a6";
    // //move.getBoardView();
    //
    // //Now testing the blue side
    // moveFrom = "b2";
    // moveTo = "b4";
    // board.executeMove(moveFrom, moveTo);
    //
    // moveFrom = "c7";
    // moveTo = "c5";
    // board.executeMove(moveFrom, moveTo);
    // // move.getBoardView();
    //
    // moveFrom = "c5";
    // moveTo = "b4";
    // isValid = board.executeMove(moveFrom, moveTo);
    // // move.getBoardView();
    //
    // moveFrom = "c2";
    // moveTo = "c3";
    // board.executeMove(moveFrom, moveTo);
    //
    // //move.getBoardView();
    //
    // moveFrom = "b4";
    // moveTo = "c3";
    // board = board.executeMove(moveFrom, moveTo);

}
