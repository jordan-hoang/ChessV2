//
// Created by jordan on 2/12/20.
//

#include "../include/ChessController.h"
#include "ChessCoordinate.h"



//Also responsable for converting to chessCoordinates.



//Checks to see if the string is valid in this program.
bool ChessController::validChessStringInput(std::string &input)  {
    if(input.size() != 5){
        return false;
    }
    return (input[2] == ',');
}


inline bool isValidChar(char a){
    return (a < 'z' && a > 'a');
}

inline bool isValidNum(char a){
    return (a <= '9' && a >= '0');
}

// Converting to chess coordinates here.
std::pair<ChessCoordinate, ChessCoordinate>
ChessController::convertChessCoordinate(std::string input, bool &valid) {

    ChessCoordinate to;
    ChessCoordinate from;
    if(validChessStringInput(input)  )
    {
        to.col = input[0] - 'a';
        to.row = input[1] - '0';

        from.col = input[3] - 'a';
        from.row = input[4] - '0';


        if(to.isValid() && from.isValid()){
            valid = true;
            return std::make_pair(to,from);
        }
    }

    to.row = -1;
    to.col = -1;
    from.row = -1;
    from.col = -1;
    valid = false;
    return std::make_pair(to,from);
}




void ChessController::playGame() {

    std::string input;
    bool valid_input = false;
    std::pair<ChessCoordinate, ChessCoordinate> moves;

    while( !chessBoard.isGameOver()  ){
        chessBoard.printChessBoard();

        std::cin >> input;
        convertChessCoordinate(input, valid_input);
        if( valid_input ) {
            chessBoard.executeMove(moves.first, moves.second);
        } else{
            std::cout << "Invalid input!\n";
        }

    }






}