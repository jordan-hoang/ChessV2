add_library(chessPiece
        src/Bishop.cpp
        src/King.cpp
        src/Piece.cpp
        )

target_include_directories(${chessPiece}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )