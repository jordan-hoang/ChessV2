# Utility headers and code required by all the other modules inside our chess project.
# Ex. ChessPiece and ChessController both depend on ChessCoordinate

add_library(${Network}
        src/Network.cpp

        )

target_include_directories(${Network}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # Gives libraries outside of this folder access to include (Header files)
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )


