//
// Created by jordan on 2/4/20.
//

#include "ChessBoard.h"
#include "Piece.h"

#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "NullPiece.h"


smartRow ChessBoard::genBackRank(Color c, bool upper) {
    smartRow myRow;

    if(upper) {
        myRow.push_back(std::make_unique<Rook>(c, 'R'));
        myRow.push_back(std::make_unique<Knight>(c, 'N'));
        myRow.push_back(std::make_unique<Bishop>(c, 'B'));
        myRow.push_back(std::make_unique<Queen>(c, 'Q'));
        myRow.push_back(std::make_unique<King>(c, 'K'));
        myRow.push_back(std::make_unique<Bishop>(c, 'B'));
        myRow.push_back(std::make_unique<Knight>(c, 'N'));
        myRow.push_back(std::make_unique<Rook>(c, 'R'));
    } else{
        myRow.push_back(std::make_unique<Rook>(c, 'r'));
        myRow.push_back(std::make_unique<Knight>(c, 'n'));
        myRow.push_back(std::make_unique<Bishop>(c, 'b'));
        myRow.push_back(std::make_unique<Queen>(c, 'q'));
        myRow.push_back(std::make_unique<King>(c, 'k'));
        myRow.push_back(std::make_unique<Bishop>(c, 'b'));
        myRow.push_back(std::make_unique<Knight>(c, 'n'));
        myRow.push_back(std::make_unique<Rook>(c, 'r'));

    }

    return std::move(myRow);
}


/**
 * Intializes a chess game.
 */
ChessBoard::ChessBoard() : isWhiteTurn{true}, GameOver{false} {

    chessboard_.push_back( genBackRank(Color::BLACK, true) );
    smartRow myRow;
    for(int i = 0; i < 8; i++) {
        myRow.push_back(std::make_unique<Pawn>(Color::BLACK,  'P'));
    }
    chessboard_.push_back(std::move(myRow));

    ////Generate Empty Squares.
    for(int i = 2; i < 6; i++){
        std::vector<std::unique_ptr<Piece>> row;
        for(int j = 0; j < 8; j++){
            auto a = std::make_unique<NullPiece>();
            row.push_back(std::move(a));
        }
        chessboard_.push_back(std::move(row));
    }

    //Generate white side pieces
    myRow.clear();
    for(int i = 0; i < 8; i++) {
        myRow.push_back(std::make_unique<Pawn>(Color::WHITE,  'p'));
    }
    chessboard_.push_back(std::move(myRow));
    chessboard_.push_back( genBackRank(Color::WHITE, false) );

    whiteKing = {0,4};
    blackKing = {7,4};
}

void ChessBoard::printChessBoard() const {
    for(const auto & i : chessboard_){
        for(const auto & j : i){
            std::cout << static_cast<char>( j->getSymbol() ) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 * Returns the state of the board as a string.
 * It's used to get the state of the board to return to the players.
 * @return A string that represents the state of the board
 */
std::string ChessBoard::getChessBoardString() const {
    std::string rst;
    for(const auto & i : chessboard_){
        for(const auto & j : i){
            rst +=  static_cast<char>( j->getSymbol());
        }
    }
    return rst;
}


const std::vector<smartRow> &ChessBoard::getChessboard() const {
    return chessboard_;
}

bool ChessBoard::isGameOver() const {
    return GameOver;
}

std::unique_ptr<ChessMove> ChessBoard::executeMove(ChessCoordinate from, ChessCoordinate to) {

    //this->chessboard_[from.row][from.col]->validateMove(from,to, *this);

    bool result = false;
    const Piece * fromPiece = getPiece(from);
    if(this->isWhiteTurn && fromPiece->getColor() == Color::WHITE ||
            !isWhiteTurn && fromPiece->getColor() == Color::BLACK)
    {
        result = this->chessboard_[from.row][from.col]->validateMove(from, to, *this);
    }

     if(result) {
          isWhiteTurn = !isWhiteTurn;

         std::unique_ptr<Piece> killedPiece = takePiece(to);
         std::unique_ptr<ChessMove> chess_move =
             std::make_unique<ChessMove>(std::make_pair(from,to), std::move(killedPiece));
         chess_move->wasFirstMoved = this->getPiece(from)->getHasMoved();

         this->movePiece(from, to); // this will set the spot to null.
         return std::move(chess_move);
     }

    return nullptr;  // For now.
}


Piece *const ChessBoard::getPiece(int row, int col) const {
    return chessboard_[row][col].get();
}

const Piece *ChessBoard::getPiece(ChessCoordinate a) const {
    return chessboard_[a.row][a.col].get();
}

std::unique_ptr<Piece> ChessBoard::takePiece(ChessCoordinate a) {
    return std::move(chessboard_[a.row][a.col]);
}




//Moves a piece from A to B, given 2 coordinates, private function.
void ChessBoard::movePiece(ChessCoordinate from, ChessCoordinate to) {
    chessboard_[from.row][from.col]->setHasMoved();


    chessboard_[to.row][to.col].swap(chessboard_[from.row][from.col]);
    //This calls reset as said from here
    // https://en.cppreference.com/w/cpp/memory/unique_ptr/operator%3D
    chessboard_[from.row][from.col] = std::make_unique<NullPiece>(Color::NO_COLOR,'-');

}

ChessBoard::ChessBoard( std::vector<smartRow> chessboard) :
        chessboard_(std::move(chessboard)), isWhiteTurn{true}, GameOver{false} {}


void ChessBoard::swapPieces(ChessCoordinate &a, ChessCoordinate &b) {
    chessboard_[a.row][a.col].swap(chessboard_[b.row][b.col]);
}

void ChessBoard::setPiece(ChessCoordinate &a, std::unique_ptr<Piece> chessPiece) {
    chessboard_[a.row][a.col] = std::move(chessPiece);
}

bool ChessBoard::isThisWhiteTurn() {
    return isWhiteTurn;
}






