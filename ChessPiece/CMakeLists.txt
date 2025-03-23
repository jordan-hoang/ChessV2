# The first input is the the "name of the library you want to create
# The rest are source files that are required
add_library(chessPiece
        src/Bishop.cpp
        src/King.cpp
        src/Piece.cpp
        src/Pawn.cpp
        src/Knight.cpp
        src/Rook.cpp
        src/Queen.cpp
        src/NullPiece.cpp
        #  ../ChessUtility/src/ChessCoordinate.cpp   # This is bad!!! Used to do this, leave here as reminder
        # You should use target_link_libaries to it instead! which we do below.
        )

# When compiling chessPiece, where to look for headers and src file?!
target_include_directories(chessPiece
        PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/include   # Provides external access to header files
        PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src      # Only chessPiece has access to its src folder
)

# Link the necessary libraries chessPiece module requires to run.
target_link_libraries(chessPiece
        PUBLIC
                chessBoard
        PRIVATE
                chessUtility  # Makes it so when you include this library you won't get the headers of chessUtility to whoever decides to link to chessPiece
)
