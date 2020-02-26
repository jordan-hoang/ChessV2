//
// Created by jordan on 2/4/20.
//

#ifndef CHESSV2_CHESSBOARD_H
#define CHESSV2_CHESSBOARD_H



#include <memory>
#include <vector>

class Piece; // Not sure why I need this here, since it is already in Piece.h but okay....
enum class Color;
#include <Piece.h>
#include <ChessCoordinate.h>



typedef std::unique_ptr<Piece> smart_piece;
typedef std::vector<std::unique_ptr<Piece>> smartRow;

class ChessBoard {
private:
    std::vector<smartRow> chessboard_;
    const Piece * whiteKing;   // White king in this case refers to the king that would go first.
    const Piece * blackKing;   // Black king in this case refers to the king that would go second.
    bool isWhiteTurn;
    bool gameEnded;


    smartRow genBackRank(Color c);

public:
    ChessBoard();
    void printChessBoard() const;
    bool isGameEnded() const;

    bool executeMove(ChessCoordinate from, ChessCoordinate to);



    const std::vector<smartRow> &getChessboard() const;


};


#endif //CHESSV2_CHESSBOARD_H