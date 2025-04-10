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

    a.set(6,0);
    b.set(4,0);
    EXPECT_EQ(my_board.executeMove(a,b), true);

    a.set(1,7);
    b.set(3,7);
    EXPECT_EQ(my_board.executeMove(a,b), true);

    a.set(7,0);
    b.set(6,0);
    EXPECT_EQ(my_board.executeMove(a,b), true);

    a.set(0,7);
    b.set(5,7);
    EXPECT_EQ(my_board.executeMove(a,b), false);

    a.set(0,7);
    b.set(2,7);
    EXPECT_EQ(my_board.executeMove(a,b), true);


    a.set(6,0);
    b.set(4,0);
    EXPECT_EQ(my_board.executeMove(a,b), false);

    a.set(6,0);
    b.set(3,0);
    EXPECT_EQ(my_board.executeMove(a,b), false);


    a.set(6,0);
    b.set(5,0);
    EXPECT_EQ(my_board.executeMove(a,b), true);



    a.set(2,7);
    b.set(2,4);
    EXPECT_EQ(my_board.executeMove(a,b), true);

    a.set(6,3);
    b.set(5,3);
    EXPECT_EQ(my_board.executeMove(a,b), true);


    a.set(2,4);
    b.set(2,3);
    EXPECT_EQ(my_board.executeMove(a,b), true);


    a.set(5,0);
    b.set(5,7);
    EXPECT_EQ(my_board.executeMove(a,b), false);


    a.set(5,0);
    b.set(5,6);
    EXPECT_EQ(my_board.executeMove(a,b), false);


    a.set(5,0);
    b.set(5,4);
    EXPECT_EQ(my_board.executeMove(a,b), false);

    a.set(5,0);
    b.set(5,3);
    EXPECT_EQ(my_board.executeMove(a,b), false);

    a.set(5,0);
    b.set(5,2);
    EXPECT_EQ(my_board.executeMove(a,b), true);

    //my_board.printChessBoard();

}