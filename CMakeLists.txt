cmake_minimum_required(VERSION 3.1)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Libraries
set(chessPiece "chessPiece")
set(chessBoard "chessBoard")
set(chessController "chessController")



add_executable(ChessV2 main.cpp)

#Link the libraries (moudles) that ChessV2 requires in order to run)
target_link_libraries(ChessV2
        ${chessPiece}
        ${chessBoard}
        ${chessController}
        )

# Cmake then goes into these directories and executes their CMakeList files as well
add_subdirectory(test)
add_subdirectory(Pieces)
add_subdirectory(ChessBoard)
add_subdirectory(ChessController)