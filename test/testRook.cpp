//
// Created by jordan on 3/6/20.
//
#include <gtest/gtest.h>
#include "ChessBoard.h"
#include <memory>


TEST(testRook, testBasic){

    ChessBoard my_board;
    //my_board.printChessBoard();

    ChessCoordinate a{7,0};
    ChessCoordinate b{5,0};

    std::unique_ptr<ChessMove> is_valid =  my_board.executeMove(a,b);
    EXPECT_EQ(is_valid, nullptr) << "Rook just went right through a pawn (No collision detection) \n";

    // 2. Valid Pawn Move
    a.set(6,0); b.set(4,0);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);

    //my_board.printChessBoard();
    // 3. Valid Pawn Move (Black)
    a.set(1,7); b.set(3,7);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);



    a.set(7,0);
    b.set(6,0);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);



    // Invalid move.
    a.set(0,7); b.set(5,7);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);


    a.set(0,7);
    b.set(2,7);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);



    a.set(6,0);
    b.set(4,0);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);


    a.set(6,0);
    b.set(3,0);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);


    a.set(6,0);
    b.set(5,0);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);



    a.set(2,7);
    b.set(2,4);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);

    // 1. Valid Move (Expected to succeed)
    a.set(6,3);
    b.set(5,3);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);

    // 2. Valid Move (Expected to succeed)
    a.set(2,4);
    b.set(2,3);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);

    // 3. Invalid Move (Expected to fail/collision)
    a.set(5,0);
    b.set(5,7);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);

    // 4. Invalid Move (Expected to fail/collision)
    a.set(5,0);
    b.set(5,6);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);


    a.set(5,0);
    b.set(5,4);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);

    a.set(5,0);
    b.set(5,3);
    EXPECT_EQ(my_board.executeMove(a,b), nullptr);

    a.set(5,0);
    b.set(5,2);
    EXPECT_NE(my_board.executeMove(a,b), nullptr);

    //my_board.printChessBoard();
}