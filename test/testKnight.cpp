//
// Created by jordan on 2/27/20.
//



#include <gtest/gtest.h>
#include <NullPiece.h>
#include <Knight.h>
#include "ChessCoordinate.h"

bool pieceMoved(ChessBoard &board, ChessCoordinate a, ChessCoordinate b);

TEST(TestKnight, testMovement){

    ChessBoard board;
    ChessCoordinate a{7,1};
    ChessCoordinate b{5,0};
    bool passed = false;

    passed = pieceMoved(board,a,b);
    EXPECT_EQ(passed,true);


    a.set(0,6);
    b.set(2,7);
    passed = pieceMoved(board,a,b);


    a.set(2,0);
    b.set(1,2);
    passed = pieceMoved(board,a,b);
    EXPECT_EQ(passed,false);


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

    ChessCoordinate a{7,1};
    ChessCoordinate b{5,0};
    board.executeMove(a, b);

    board.printChessBoard();



}