//
// Created by jordan on 2/12/20.
//
#include "ChessController.h"
#include "json.hpp"
#include <thread>


ChessController::ChessController()
    : chessNetwork_(std::make_shared<ChessNetwork>())
{
    // This so we have access to chessController inside lambda.
    chessNetwork_->setMessageReceivedCallback([this](const std::string message) -> std::string {
        return this->onClientMessageReceived(message);
    });

}

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
    std::pair<ChessCoordinate, ChessCoordinate> moves;

    std::thread networkThread([this] {
        this->chessNetwork_->startNetworkLoop();
    });

    networkThread.detach(); // I remember there were other ways of running threads....

    while( !chessBoard.isGameOver()  )
    {
        chessBoard.printChessBoard();
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }

}


// Callback function that is passed to chessNetwork.
std::string ChessController::onClientMessageReceived(const std::string &message) {

    std::cout << message << std::endl;
    bool valid_move = false;

    //std::pair<ChessCoordinate, ChessCoordinate> moves = convertChessCoordinate(message, valid_input);
    nlohmann::json jsonData = nlohmann::json::parse(message);
    std::pair<ChessCoordinate, ChessCoordinate> moves;

    moves.first = jsonData["from"];
    moves.second = jsonData["to"];

    valid_move = chessBoard.executeMove(moves.first, moves.second);

    if (!valid_move) {
        std::cerr << "Invalid move\n";
        std::cerr << "DEBUG: " << moves.first << moves.second << std::endl << "\n"; // For debugging.
    }

    nlohmann::json jsonResponse;

    jsonResponse["valid"] = valid_move;
    jsonResponse["message"] = valid_move ? "Move accepted" : "Invalid move";

    jsonResponse["from"] = { {"row", moves.first.row}, {"col", moves.first.col} };
    jsonResponse["to"] = { {"row", moves.second.row}, {"col", moves.second.col} };
    jsonResponse["board"] = { chessBoard.getChessBoardString() };

    //std::cout << "Dumping jsonResponseFrom(ChessController.cpp): " << jsonResponse.dump()  << "\n";

    return jsonResponse.dump(); // Dump returns it as a string you can then send to the server
}


void ChessController::threadMain() {
    this->playGame();
}

/**
 * Wait's until the thread is "joinable"
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
