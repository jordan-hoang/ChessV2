#include <iostream>
#include <memory>

#include "Piece.h"

int main() {

    Piece * b = new Bishop(true, 'b');

    b->print();

    std::unique_ptr<Bishop> piece_king(new Bishop(true, 'b') );



    return 0;
}
