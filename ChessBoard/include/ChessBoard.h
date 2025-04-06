//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_CHESSBOARD_H
#define CHESSV2_CHESSBOARD_H



#include <memory>
#include <vector>

class Piece; //
enum class Color;

#include "Piece.h"
#include "ChessCoordinate.h"
#include "MoveRecorder.h"

typedef std::unique_ptr<Piece> smart_piece;
typedef std::vector<std::unique_ptr<Piece>> smartRow;

class ChessBoard {
private:
    std::vector<smartRow> chessboard_;

    ChessCoordinate whiteKing;   // White king in this case refers to the king that would go first.
    ChessCoordinate blackKing;   // Black king in this case refers to the king that would go second.
    bool isWhiteTurn;            // Checks to see whose turn it is.
    bool GameOver;              // Variable to determine if the game has ended yet.

    smartRow genBackRank(Color c, bool upperCase);
    void movePiece(ChessCoordinate from, ChessCoordinate to);

public:
    ChessBoard();
    ChessBoard(std::vector<smartRow> chessboard);

    void printChessBoard() const;
    std::string getChessBoardString() const;

    bool isGameOver() const;
    bool executeMove(ChessCoordinate from, ChessCoordinate to);

    void swapPieces(ChessCoordinate &a, ChessCoordinate &b);
    void setPiece(ChessCoordinate &a,  std::unique_ptr<Piece> chessPiece);


    bool isThisWhiteTurn();

    Piece *const getPiece(int row, int col) const;
    Piece *const getPiece(ChessCoordinate a) const;
    const std::vector<smartRow> &getChessboard() const;


};


#endif //CHESSV2_CHESSBOARD_H
