cmake_minimum_required(VERSION 3.15)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)

set(chessPiece "chessPiece")
set(chessBoard "chessBoard")



add_executable(ChessV2 main.cpp ChessController.h ChessController.cpp )

target_link_libraries(ChessV2
        ${chessPiece}
        ${chessBoard}

        )


add_subdirectory(test)
add_subdirectory(Pieces)
add_subdirectory(ChessBoard)