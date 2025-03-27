//
// Created by jordan on 2/12/20.
//

#ifndef CHESSV2_CHESSCOORDINATE_H
#define CHESSV2_CHESSCOORDINATE_H


#include <json.hpp>
#include <ostream>
using json = nlohmann::json;

struct ChessCoordinate {
        int row;
        int col;

        bool operator==(const ChessCoordinate &a) const {
            return ( row == a.row  && col == a.col );
        }
        ChessCoordinate operator+(const ChessCoordinate &b) const {
            return ChessCoordinate{row + b.row, col + b.col};
        }
        ChessCoordinate operator-(const ChessCoordinate &b) const {
            return ChessCoordinate{row - b.row, col - b.col};
        }
        ChessCoordinate& operator++(){
            row++;
            col++;
            return *this;
        }
        ChessCoordinate toOne(){
            ChessCoordinate rst = *this;
            if(rst.row == 0){
                rst.row = 0;
            } else{
                rst.row = 1;
            }
            if(rst.col == 0){
                rst.col = 0;
            } else{
                rst.col = 1;
            }
            return rst;
        }
        
        ChessCoordinate& operator=(const ChessCoordinate &copy){
            row = copy.row;
            col = copy.col;
            return *this;
        }


        bool isValid() const;

        friend std::ostream &operator<<(std::ostream &os, const ChessCoordinate &coordinate) {
            os << "{"  << coordinate.row << ", " << coordinate.col << "}";
            return os;
        }

        ChessCoordinate set(int row, int col);
        ChessCoordinate() : row(-1), col(-1){}
        ChessCoordinate(int enteredRow, int enteredCol) : row(enteredRow), col(enteredCol) {}


        // Declare the conversion from_json
        friend void from_json(const nlohmann::json& j, ChessCoordinate& coord);
        friend void to_json(nlohmann::json& j, const ChessCoordinate& coord);
};


#endif //CHESSV2_CHESSCOORDINATE_H
