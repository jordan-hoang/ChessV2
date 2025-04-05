//
// Created by jordan on 30/04/19.
//
// THIS IS AN IMPORT FROM CHESS V1 that I totally forgot about!

// A Class that keeps track of all the moves that were made in a game.
// Is implemented like a stack, used when you want to undo a move or a state.
// Keeps track of only moves so it doesn't store the previous state of the board,
// Takes less space, also perhaps you can output the moves to a txt file then you would be able to
// save replays of old games.

#include "MoveRecorder.h"
#include <sstream>
#include "ChessBoard.h"




void ChessMove::undoMove(ChessBoard &myChessBoard) {

        ChessCoordinate start = move.first;
        ChessCoordinate end = move.second;

        myChessBoard.swapPieces(start,end);
        myChessBoard.setPiece(start, std::move(pieceKilled) );

        //Handling special king case,
        // This undos the flag that stops you from castling. Needs to be updated to chessV2 design.
        //
        // if(moveTo.getPieceUnit() == PieceUnit::KING ) {
        //     ChessCoordinate blueKingStart = {7,4};
        //     ChessCoordinate redKingStart = {0,4};
        //
        //     if(moveTo.getColor() == Color::BLACK && redKingStart == start){
        //         moveTo.setHasMoved(false);
        //     }else if(moveTo.getColor() == Color::WHITE && blueKingStart == start){
        //         moveTo.setHasMoved(false);
        //     }else if(moveTo.getColor() == Color::COLORLESS ){
        //
        //     }
        //
        // }

}







MoveRecorder::MoveRecorder() = default;

//Adds a move the the moveRecorder.
void MoveRecorder::addMove(ChessCoordinate startPos,  ChessCoordinate finishPos, std::unique_ptr<Piece> killed) {
    //std::unique_ptr<ChessMove> tmp(new ChessMove());
    // tmp->move = std::make_pair(startPos,finishPos);
    // tmp->pieceKilled = killed;
    std::unique_ptr<ChessMove> tmp = std::make_unique<ChessMove>(
                                        std::make_pair(startPos,finishPos),
                                        std::move(killed));

    m_listOfGameMoves.emplace_back( std::move(tmp) ); //You need to use std::move to transfer ownership.
}

void MoveRecorder::addMove(std::unique_ptr<ChessCastle> chessMove) {
    m_listOfGameMoves.emplace_back( std::move(chessMove) );
}

void MoveRecorder::addMove(std::unique_ptr<ChessMove> chessMove) {
    m_listOfGameMoves.emplace_back( std::move(chessMove) );
}


void MoveRecorder::removeLastMove() {
    m_listOfGameMoves.pop_back();
}

// Maybe get a weak pointer instead of a raw pointer?
ChessMove * MoveRecorder::getLastMove() {
    if(hasMove()){
        return m_listOfGameMoves.back().get();
    }
    ChessMove * tmp = nullptr;
    return tmp;
}

bool MoveRecorder::hasMove() const {
    return !m_listOfGameMoves.empty();
}

std::string MoveRecorder::printMoves() {
    std::stringstream outputStream;
    for( const auto &myPair : m_listOfGameMoves) {
        outputStream << myPair->move.first << ", " << myPair->move.second << "\n";
    }
    return outputStream.str();
}


/**
 *Janky code
 * @param board The board on which you want to "undo a move on"
 */
void MoveRecorder::undoMove(ChessBoard &board) {
    if(!hasMove()){
        return;
    }

    getLastMove()->undoMove(board);
    removeLastMove();

}