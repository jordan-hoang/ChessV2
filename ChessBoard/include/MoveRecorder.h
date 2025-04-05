//
// Created by jordan on 30/04/19.
//

#ifndef CHESS_MOVERECORDER_H
#define CHESS_MOVERECORDER_H
#pragma once


#include <utility>
#include "Piece.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class ChessBoard;

using std::pair;
using std::vector;

/// Note polymorphism not actually needed to be used here at all
/// Since the difference between singleChessMove and MultiChessMove is irrelevant
/// I only chose to use polymorphism because I wanted to try using it at least once in C++.
/// You can instead have a vector that stores  a vector of moves and do away with this structure
/// -Having a vector of vectors is also more flexible and better but lets just use polymorphism for castling


// Old chessRecorder class from V1, that was modified... doesn't work fully.
struct ChessMove {
    pair<ChessCoordinate,ChessCoordinate> move;
    std::unique_ptr<Piece> pieceKilled;

    // Tests the ability to undo moves.
    virtual void undoMove(ChessBoard &myChessBoard);

    ChessMove() = default;
    ChessMove(ChessMove&&) = default;

    ChessMove(const ChessMove&) = delete;
    ChessMove& operator=(const ChessMove&) = delete;


    ChessMove(const ChessCoordinate &start, const ChessCoordinate &finish){
        move.first  = start;
        move.second = finish;
    }

    ChessMove( pair<ChessCoordinate,ChessCoordinate> userMove, std::unique_ptr<Piece> piece) :
            move( std::move(userMove) ), pieceKilled(std::move(piece)){}

    virtual ~ChessMove() = default;

};

struct ChessCastle : public ChessMove {

    ChessMove rookMoved;

    void undoMove(ChessBoard &myChessBoard)  override {

        const ChessCoordinate &start = move.first;
        const ChessCoordinate &end =  move.second;



        // OLd chess V1 Code.
        //Piece &moveFromKing = board[end.row][end.col];
        //Piece &moveToKing   = board[start.row][start.col];
        // Piece::updatePiece(moveFromKing,moveToKing);
        // moveToKing.setHasMoved(false);
        //
        //
        // //Repeat for rook
        // const ChessCoordinate &startRook = rookMoved.move.first;
        // const ChessCoordinate &endRook =  rookMoved.move.second;
        // Piece::updatePiece( board[endRook.row][endRook.col], board[startRook.row][startRook.col] );
        // board[startRook.row][startRook.col].setHasMoved(false);


        std::cout << "For debugging the coordinates of rook and king are \n";
        //std::cout << "King  : " << start << ", " << end << "\n";
        //std::cout << "Rook : " << startRook << ", " <<  endRook << "\n";

    }

    ChessCastle(const ChessMove &rook, const ChessMove &king){
        // rookMoved = rook;
        // move.first = king.move.first;
        //
        // pieceKilled = Piece{PieceUnit::NONE,Color::COLORLESS};
        // move.second = king.move.second;
    }
    ~ChessCastle() override = default;

private:
    ChessCastle() = default;


};

struct MoveEnPassant : public ChessMove{

    ChessCoordinate coordinatePawn;

    void undoMove(ChessBoard &myChessBoard) override {
        // const ChessCoordinate &start = move.first;
        // const ChessCoordinate &end =  move.second;
        //
        // Piece &moveFrom= board[end.row][end.col];
        // Piece &moveTo   = board[start.row][start.col];
        // Piece::updatePiece(moveFrom,moveTo);
        //
        // //Now we need to restore the killedPawn
        //
        // board[coordinatePawn.row][coordinatePawn.col] = pieceKilled;

        std::cout << "UNDO ENPASSANT UNIMPLEMENTED\n";
    }


    MoveEnPassant(const ChessMove &movePawn, const ChessCoordinate &killedPiece){
        // move = movePawn.move;
        // pieceKilled = movePawn.pieceKilled;
        // coordinatePawn = killedPiece;
    }

private:
    MoveEnPassant() = default;

};

/**
 * A class that records moves, and also checks for move reptition
 */
class MoveRecorder {
    public:
        void addMove(ChessCoordinate, ChessCoordinate, std::unique_ptr<Piece> killedPiece);
        void addMove( std::unique_ptr<ChessCastle> chessMove );
        void addMove( std::unique_ptr<ChessMove> chessMove) ;

        void removeLastMove();
        void undoMove(ChessBoard &board);

        std::string printMoves();

        bool hasMove() const;
        ChessMove * getLastMove();
        MoveRecorder();

    private:
        vector<std::unique_ptr<ChessMove>> m_listOfGameMoves; // More like a stack of moves?

};


#endif //CHESS_MOVERECORDER_H