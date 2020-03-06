cmake_minimum_required(VERSION 3.1)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)

set(chessPiece "chessPiece")
set(chessBoard "chessBoard")
set(chessController "chessController")


add_executable(ChessV2 main.cpp)

target_link_libraries(ChessV2
        ${chessPiece}
        ${chessBoard}
        ${chessController}
        )


add_subdirectory(test)
add_subdirectory(Pieces)
add_subdirectory(ChessBoard)
add_subdirectory(ChessController)