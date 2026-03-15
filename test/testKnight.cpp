//
// Created by jordan on 2/27/20.
//



#include <gtest/gtest.h>
#include <NullPiece.h>
#include <Knight.h>
#include "../ChessUtility/include/ChessCoordinate.h"

bool pieceMoved(ChessBoard &board, ChessCoordinate a, ChessCoordinate b);

TEST(TestKnight, testMovement){
    ChessBoard board;
    ChessCoordinate a{7,1}; // b1 (White Knight)
    ChessCoordinate b{5,0}; // a3
    bool passed = false;

    // 1. Valid jump: White Knight b1 to a3
    passed = pieceMoved(board, a, b);
    EXPECT_TRUE(passed) << "Knight failed valid move from b1 to a3";

    // 2. Valid jump: Black Knight g8 to h6
    a.set(0,6);
    b.set(2,7);
    passed = pieceMoved(board, a, b);
    EXPECT_TRUE(passed) << "Knight failed valid move from g8 to h6";

    // 3. ILLEGAL Move: (Assuming no piece at 2,0 or move is invalid)
    // Testing that the Knight cannot perform a non-L-shaped move
    a.set(2,0);
    b.set(1,2);
    passed = pieceMoved(board, a, b);
    EXPECT_FALSE(passed) << "Knight allowed an illegal move from a6 to c7";
}


//Feels irrelevant....
std::vector<smartRow> initOneKnight(){
    std::vector<smartRow> myBoard;
    ////Generate Empty Squares.
    for(int i = 0; i < 4; i++){
        std::vector<std::unique_ptr<Piece>> row;
        for(int j = 0; j < 8; j++){
            auto a = std::make_unique<NullPiece>();
            row.push_back(std::move(a));
        }
        myBoard.push_back(std::move(row));
    }

    std::vector<std::unique_ptr<Piece>> row;
    for(int i = 0; i < 3 ; i++){
        auto a = std::make_unique<NullPiece>();
        row.push_back(std::move(a));
    }
    row.push_back( std::make_unique<Knight>(Color::WHITE, 'K') );
    for(int i = 0; i < 4 ; i++){
        auto a = std::make_unique<NullPiece>();
        row.push_back(std::move(a));
    }

    myBoard.push_back(std::move(row));
    for(int j = 0; j < 2; j++) {
        for (int i = 0; i < 8; i++) {
            auto a = std::make_unique<NullPiece>();
            row.push_back(std::move(a));
        }
        myBoard.push_back(std::move(row));
    }

    return std::move(myBoard);
}


TEST(TestKnight, testEightMoves){
    ChessBoard board;

    // 1. White Knight: b1 to a3
    ChessCoordinate a{7,1};
    ChessCoordinate b{5,0};
    EXPECT_NE(board.executeMove(a, b), nullptr) << "Failed: Knight b1 to a3";

    // 2. Black Knight: b8 to c6
    a.set(0,1);
    b.set(2,2);
    EXPECT_NE(board.executeMove(a, b), nullptr) << "Failed: Knight b8 to c6";

    // 3. White Knight: a3 to c4
    a.set(5,0);
    b.set(4,2);
    EXPECT_NE(board.executeMove(a, b), nullptr) << "Failed: Knight a3 to c4";

    // 4. Try to eat itself (Black Knight c6 trying to move to e7 where another Black piece is)
    // Or moving to a square occupied by its own color.
    a.set(2,2);
    b.set(0,4);
    EXPECT_EQ(board.executeMove(a, b), nullptr) << "Error: Knight was allowed to capture its own team";

    // 5. Black Knight: g8 to f6
    a.set(0,6);
    b.set(2,5);
    EXPECT_NE(board.executeMove(a, b), nullptr) << "Failed: Knight g8 to f6";
}