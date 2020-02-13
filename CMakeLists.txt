cmake_minimum_required(VERSION 3.15)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)
set(chessPiece "chessPiece")


add_subdirectory(Pieces)



add_executable(ChessV2 main.cpp ChessController.cpp ChessController.h)


target_link_libraries(ChessV2
        ${chessPiece}
        )