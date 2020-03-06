add_library(${chessController}
        src/ChessController.cpp
        )

target_link_libraries(${chessController}
        ${chessBoard}
        )


target_include_directories(${chessController}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )