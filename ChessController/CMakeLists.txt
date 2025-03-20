add_library(chessController
        src/ChessController.cpp
)


# Include directories
target_include_directories(chessController
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Linking libraries
target_link_libraries(chessController
        PUBLIC
            chessUtility
            chessBoard
            chessPiece
            chessNetwork
)