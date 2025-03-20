add_library(chessBoard
        src/ChessBoard.cpp
        src/ChessCollision.cpp
        )

target_link_libraries(chessBoard
        PRIVATE
                chessPiece
                chessUtility  # ChessCoordinate
        )

target_include_directories(chessBoard
        PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src
        )