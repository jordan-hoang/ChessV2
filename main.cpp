#include "ChessController.h"

#include <boost/asio.hpp>

int main() {

    ChessController chessGame;

    chessGame.run();
    chessGame.wait();

    return 0;
}



