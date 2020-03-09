//
// Created by jordan on 3/6/20.
//
#include <gtest/gtest.h>
#include "ChessBoard.h"


TEST(testChessBoard, testBasic){

    ChessBoard my_board;
    //my_board.printChessBoard();

    ChessCoordinate a{7,0};
    ChessCoordinate b{5,0};

    bool is_valid = my_board.executeMove(a,b);
    EXPECT_EQ(is_valid, false) << "Rook just went right through a pawn (No collision detection) \n";




}