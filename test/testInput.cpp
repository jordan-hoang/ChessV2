//
// Created by jordan on 3/6/20.
//

#include "../ChessUtility/include/ChessCoordinate.h"
#include <gtest/gtest.h>
#include <ChessController.h>


TEST(TestInput, testBasic){

    ChessController my_controller;
    std::string input = "abc";
    bool result = my_controller.validChessStringInput(input);
    EXPECT_EQ(result, false);
}

///Now we want to test all sorts of inputs...
/// a1,a3
/// b2b4
/// h7,h4,
//  i0,i2
//  a9,a7   
// The above should be good enough for testing.
TEST(TestInput, testInputs){

    ChessController my_controller;
    std::string input = "a1,a3";
    bool is_valid = false;
    std::pair<ChessCoordinate, ChessCoordinate> rst;
    ChessCoordinate my_coordinate{1,0};

    rst = my_controller.convertChessCoordinate(input, is_valid);
    EXPECT_EQ( rst.first, my_coordinate );
    my_coordinate = {3,0};
    EXPECT_EQ( rst.second, my_coordinate);
    EXPECT_EQ(is_valid, true);
}

TEST(TestInput, badInput){

    ChessController my_controller;
    std::string input = "b2b4";
    bool is_valid = false;
    std::pair<ChessCoordinate, ChessCoordinate> rst;

    ChessCoordinate my_coordinate{-1,-1};
    rst = my_controller.convertChessCoordinate(input, is_valid);

    EXPECT_EQ(is_valid, false);
    EXPECT_EQ(rst.first, my_coordinate);
    EXPECT_EQ(rst.second, my_coordinate);

}

TEST(TestInput, invalidCoordinate){
    ChessController my_controller;
    std::string input = "io,i2";
    bool is_valid = false;
    std::pair<ChessCoordinate, ChessCoordinate> rst;

    ChessCoordinate my_coordinate{-1,-1};
    rst = my_controller.convertChessCoordinate(input, is_valid);

    EXPECT_EQ(is_valid, false);
    EXPECT_EQ(rst.first, my_coordinate);
    EXPECT_EQ(rst.second, my_coordinate);

}
