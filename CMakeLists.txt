# Read up on this if you forgotten the basics of cmake
# https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/

# 3.1 >= Is the beginning of what is know as modern cmake
cmake_minimum_required(VERSION 3.10)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)


# find_package(Boost REQUIRED COMPONENTS system)

add_executable(ChessV2 main.cpp)


#Link the libraries (moudles) that ChessV2 requires in order to run)
# See this answer: Very helpful
# https://stackoverflow.com/questions/26037954/cmake-target-link-libraries-interface-dependencies
target_link_libraries(ChessV2
        PRIVATE
            chessController
        )


# Cmake then goes into these directories and executes their CMakeList files as well
add_subdirectory(test)
add_subdirectory(ChessPiece)
add_subdirectory(ChessBoard)
add_subdirectory(ChessController)
add_subdirectory(ChessUtility)





