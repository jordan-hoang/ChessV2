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


### Target properties are defined in one of two scopes: INTERFACE(Public)  and PRIVATE.
#   Private properties are used internally to build the target, while interface properties are used externally by users of the target.
#   In other words, interface properties model usage requirements,
#   whereas private properties model build requirements of targets.
target_include_directories(${chessPiece}
        PUBLIC
            $<INSTALL_INTERFACE:include>                            # This only applies to make install I believe?
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # Gives libraries outside of this folder access to include (Header files)
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src     # Only the chessPiece module has access to whatever is inside it's src folder
        )

# Link the necessary libraries chessPiece module requires to run.
# This can be both private or public.....
target_link_libraries(${chessPiece}
        ${chessBoard}
        )
