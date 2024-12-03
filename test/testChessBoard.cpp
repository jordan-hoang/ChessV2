//
// Created by jordan on 3/6/20.
//
#include <gtest/gtest.h>
#include "ChessBoard.h"


TEST(testRook, testCollision){

    ChessBoard my_board;

    ChessCoordinate a{0,1};
    ChessCoordinate b{0,3};

    bool is_valid = my_board.executeMove(a,b);
    ASSERT_EQ(is_valid, false);

}