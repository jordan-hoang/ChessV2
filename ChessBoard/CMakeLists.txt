add_library(${chessBoard}
        src/ChessBoard.cpp
        src/ChessCollision.cpp
        )

target_link_libraries(${chessBoard}
        ${chessPiece}
        ${chessUtility}
        )

target_include_directories(${chessBoard}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )