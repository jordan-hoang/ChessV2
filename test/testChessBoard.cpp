//
// Created by jordan on 3/6/20.
//
#include <gtest/gtest.h>
#include "ChessBoard.h"


TEST(testChessBoard, testBasic){

    ChessBoard my_board;
    //my_board.printChessBoard();

    ChessCoordinate a{0,1};
    ChessCoordinate b{0,3};

    bool is_valid = my_board.executeMove(a,b);
    EXPECT_EQ(is_valid, false);

    //my_board.printChessBoard();    



}