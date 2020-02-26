
// Created by jordan on 2/26/20.

#include "ChessCoordinate.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../Pieces/ChessBoard.h"


TEST(BoardTest, pawn){

    ChessBoard board;

    bool val = board.executeMove({1,1},{2,1} );

    EXPECT_EQ(val, true) << "Error when moving pawn up 1 unit";

    //board.printChessBoard();




}