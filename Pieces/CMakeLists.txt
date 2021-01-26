# The first input is the the "name of the library you want to create
# The rest are source files that are required
add_library(${chessPiece}
        src/Bishop.cpp
        src/King.cpp
        src/Piece.cpp
        src/Pawn.cpp
        src/Knight.cpp
        src/Rook.cpp
        src/Queen.cpp
        src/NullPiece.cpp
        src/ChessCoordinate.cpp
        )

# This part is a bit confusing....
# I blieve <INSTALL_INTERFACE is fo
target_include_directories(${chessPiece}
        PUBLIC
            $<INSTALL_INTERFACE:include>                            # This only applies to make install I believe
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # Gives libraries outside of this folder access to include (Header files)
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src     # Only chessPiece module has access to the src no one else can peek inside src
        )

# Link the necessary libraries chessPiece module requires to run.
target_link_libraries(${chessPiece}
        ${chessBoard}
        )
