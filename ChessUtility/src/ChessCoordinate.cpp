//
// Created by jordan on 2/12/20.
//

#include "ChessCoordinate.h"



ChessCoordinate ChessCoordinate::set(int row_, int col_) {
    this->row = row_;
    this->col = col_;
    return *this;
}

bool ChessCoordinate::isValid() const {
    if(row < 0 || row >= 8){
        return false;
    }
    return !(col < 0 || col >= 8 );
}

// Deserialize
void from_json(const nlohmann::json& j, ChessCoordinate& coord) {
    j.at("row").get_to(coord.row);
    j.at("col").get_to(coord.col);
}

// Serialize.......... this is weird.
void to_json(nlohmann::json& j, const ChessCoordinate& coord) {
    j = json{
            {"row", coord.row},
            {"col", coord.col}
    };
}