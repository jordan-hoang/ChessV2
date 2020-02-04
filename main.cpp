#include <iostream>
#include <memory>

#include "Pieces/include/Piece.h"
#include "Pieces/include/Bishop.h"

int main() {

    Bishop * b = new Bishop(true, 'b');

    b->print();

    std::unique_ptr<Bishop> piece_king(new Bishop(true, 'b') );



    return 0;
}
