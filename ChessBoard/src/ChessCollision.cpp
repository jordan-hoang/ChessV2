//
// Created by jordan on 2/27/20.
//

#include <algorithm>
#include <assert.h>
#include "ChessCollision.h"

/**
 * Scans through the 2 coordinates and checks if there is anything in-between these 2 values.
 * Returns true if there is nothing, else returns false.
 * @param start - starting postion  (order doesn't matter)
 * @param finish - finishing position
 * @param b - The board you want to check
 * @return -
 */
bool ChessCollision::isVerticalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b) {

    int begin = std::min(start.row,finish.row);
    int end = std::max(start.row,finish.row);

    // + 1 for the space in front of it
    for(int i = begin + 1; i < end ; ++i){
        if(b.getPiece({i,start.col})->getColor() != Color::NO_COLOR ){
            return false;
        }
    }

    return true;
}

bool ChessCollision::isHorizontalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b) {

    #ifdef DEBUG
        assert(start.row == finish.row); //Assuming that Piece checks for you.
    #endif

    int iterBegin = std::min(start.col,finish.col ) + 1 ;
    int iterEnd   =  std::max(start.col,finish.col) ;

    //Exclusive loop.
    for(int i = iterBegin; i < iterEnd; i++){
        auto piece_color = b.getPiece({start.row,i})->getColor();
        if(piece_color != Color::NO_COLOR) {
            return false;
        }
    }
    return true;

}

bool ChessCollision::isDiagonalPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b) {

    // A bishop's diagonal can be defined by y = x or y = -x
    int endIter = abs(finish.col - start.col);

    int curX = start.col;
    int curY = start.row;

    int changeX = ( (finish.col - start.col) > 0 ) ? 1 : -1;
    int changeY = ( (finish.row - start.row) > 0 ) ? 1 : -1;

    for(int i = 0; i < endIter - 1; ++i){
        curX += changeX;
        curY += changeY;
        auto piece_color = b.getPiece(curY,curX)->getColor();
        if(piece_color != Color::NO_COLOR   ){
            return false;
        }
    }

    return true;

}

bool ChessCollision::isPathClear(ChessCoordinate start, ChessCoordinate finish, const ChessBoard &b){


    int diffRow = abs( finish.row - start.row);
    int diffCol = abs( finish.col - start.col);

    // You are moving horizontally
    if( start.row == finish.row && start.col != finish.col ){
        return isHorizontalPathClear(start, finish, b);
    }

    // You are moving vertical
    else if( start.row != finish.row && start.col == finish.col ) {
        return isVerticalPathClear(start, finish, b);
    }

    //For diagonal points we need to calculate the slope so...
    else if( diffRow == diffCol ){
        return isDiagonalPathClear(start, finish, b);
    }

    return false;
}