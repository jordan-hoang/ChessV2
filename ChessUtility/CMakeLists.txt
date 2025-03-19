# This is a pretty small library!
add_library(chessUtility
        src/ChessCoordinate.cpp
)

# Define include paths — PUBLIC means that any other target linking to this will inherit these paths
target_include_directories(chessUtility
        PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# We don't depend on anything else so theres no need to use
# target_link_libaries for ChessUtility.