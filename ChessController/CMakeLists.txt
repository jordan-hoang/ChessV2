# The game control class, which has functions to manipulate the board
add_library(chessController
        src/ChessController.cpp
)

target_link_libraries(chessController
        PUBLIC
                chessUtility # Public because you want it's headers!
                chessBoard   # ChessController.h includes ChessBoard.h.
                chessPiece   # It needs this too.
)


target_include_directories(${chessController}
        PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src
)