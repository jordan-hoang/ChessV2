# The game control class, which has functions to manipulate the board
add_library( ${chessController}
        src/ChessController.cpp
        )

target_link_libraries( ${chessController}
        ${chessBoard}
        ${chessUtility}
        )

#Hello friends
target_include_directories(${chessController}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>     #Tells this cmake to look inside the include folder
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )