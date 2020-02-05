#include <iostream>
#include <memory>
#include <string.h>

#include "Pieces/ChessBoard.h"


typedef std::vector<std::unique_ptr<int>> vec3;
typedef std::unique_ptr<int> smartInt;

int main() {

    ChessBoard a;
    a.printChessBoard();




    return 0;
}
