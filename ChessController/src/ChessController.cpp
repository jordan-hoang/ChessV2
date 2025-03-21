//
// Created by jordan on 2/12/20.
//
#include "ChessController.h"
#include <thread>


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
    bool valid_move = false;
    std::pair<ChessCoordinate, ChessCoordinate> moves;

    while( !chessBoard.isGameOver()  )
    {

        chessBoard.printChessBoard();
        std::cin >> input; // Read input from the user's keyboard.... need to modify to recieve input from the network.
        moves = convertChessCoordinate(input, valid_input);

        if( valid_input ) {
            valid_move = chessBoard.executeMove(moves.first, moves.second);
        } else{
            std::cout << "Invalid input\n";
        }
        if(!valid_move){
            std::cout << "Invalid move\n";
        }

    }

}

void ChessController::threadMain() {
    this->playGame();
}

/**
 * Wait's untill the thread is "joinable"
 */
void ChessController::wait() {
    if(_chessThread.joinable()) {
        _chessThread.join();
    }
}

ChessController::~ChessController() {
    if(_chessThread.joinable()) {
        _chessThread.join();
    }
}
