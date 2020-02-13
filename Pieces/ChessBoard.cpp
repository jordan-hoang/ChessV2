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




smartRow ChessBoard::genBackRank(Color c) {
    smartRow myRow;
    myRow.push_back( std::make_unique<Rook> (c,'R') );
    myRow.push_back( std::make_unique<Knight> (c,'N') );
    myRow.push_back( std::make_unique<Bishop> (c,'B') );
    myRow.push_back( std::make_unique<Queen> (c,'Q') );
    myRow.push_back( std::make_unique<King> (c,'K') );
    myRow.push_back( std::make_unique<Bishop> (c,'B') );
    myRow.push_back( std::make_unique<Knight> (c,'N') );
    myRow.push_back( std::make_unique<Rook> (c,'R') );

    return std::move(myRow);
}

ChessBoard::ChessBoard() : isWhiteTurn{true}, gameEnded{false} {

    chessboard_.push_back( genBackRank(Color::BLACK) );
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
        myRow.push_back(std::make_unique<Pawn>(Color::WHITE,  'P'));
    }
    chessboard_.push_back(std::move(myRow));
    chessboard_.push_back( genBackRank(Color::WHITE) );

    whiteKing = chessboard_[0][4].get();
    blackKing = chessboard_[7][4].get();

}

void ChessBoard::printChessBoard() const {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::cout << static_cast<char>( chessboard_[i][j]->getSymbol() ) << " ";
        }
        std::cout << "\n";
    }
}

const std::vector<smartRow> &ChessBoard::getChessboard() const {
    return chessboard_;
}



bool ChessBoard::isGameEnded() const {
    return gameEnded;
}

bool ChessBoard::executeMove(ChessCoordinate from, ChessCoordinate to) {


    return false;
}




