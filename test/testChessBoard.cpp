//
// Created by jordan on 3/6/20.
//
#include <gtest/gtest.h>
#include "ChessBoard.h"


TEST(testRook, testCollision){

    ChessBoard my_board;

    // Typically {0,1} is a Pawn in standard setup.
    // If you're testing a Rook jumping over it:
    ChessCoordinate a{0,0}; // Rook
    ChessCoordinate b{0,2}; // Target square behind the pawn at {0,1}

    // executeMove now returns nullptr on failure
    auto move_result = my_board.executeMove(a, b);

    ASSERT_EQ(move_result, nullptr) << "Rook should not be able to jump over the pawn!";
}