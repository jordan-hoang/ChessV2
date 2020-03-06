#include <iostream>
#include <memory>
#include <string.h>
#include <ChessController.h>


int main() {

    ChessController a;

    std::string input = "a1,a2";

    a.validChessStringInput(input);



    return 0;
}
