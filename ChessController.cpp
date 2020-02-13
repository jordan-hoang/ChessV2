//
// Created by jordan on 2/12/20.
//

#include "ChessController.h"
#include "Pieces/include/ChessCoordinate.h"



//Also responsable for converting to chessCoordinates.



//Checks to see if the string is valid in this program.
bool ChessController::validateInput(std::string &input)  {
    if(input.size() < 5 || input.size() != 5){
        return false;
    }
    return input[2] == ',';
}


bool isValidChar(char a){
    return (a < 'z' && a > 'a');
}

bool isValidNum(char a){
    return (a <= '9' && a >= '0');
}



// Converting to chess coordinates here.
bool ChessController::convertChessCoordinate(ChessCoordinate &a, ChessCoordinate &b, std::string input) {
    if(isValidChar(input[0]) || isValidChar(input[3]) ||isValidNum(input[1]) ||isValidNum(input[4])) {
        a.col = input[0] - 'a';
        a.row = input[1] - '0';

        b.col = input[3] - 'a';
        b.row = input[4] - '0';


        if(a.isValid() && b.isValid()){
            return true;
        }
    }

    return false;
}



void ChessController::playGame() {

    std::string input;

    ChessCoordinate a;
    ChessCoordinate b;

    while( !chessBoard.isGameEnded()  ){
        std::cin >> input;

        if(validateInput(input) && convertChessCoordinate(a,b, input)) {
            chessBoard.executeMove(a,b);
        }
        std::cout << input << "\n";
    }






}