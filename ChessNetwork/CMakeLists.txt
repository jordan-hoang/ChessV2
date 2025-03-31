add_library(chessNetwork
        src/ChessNetwork.cpp
        src/ClientHandler.cpp
)

# Include directories
target_include_directories(chessNetwork
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${Boost_INCLUDE_DIRS}
)

# Linking libraries
target_link_libraries(chessNetwork
        PRIVATE
            ws2_32
            chessUtility
)