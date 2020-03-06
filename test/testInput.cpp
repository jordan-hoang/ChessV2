//
// Created by jordan on 3/6/20.
//




#include "ChessCoordinate.h"
#include "../ChessController/include/ChessController.h"
#include <gtest/gtest.h>





TEST(TestInput, testMovement){

    ChessController my_controller;
    std::string input = "abc";

    bool result = my_controller.validChessStringInput(input);

    EXPECT_EQ(result, false);

}