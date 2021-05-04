add_subdirectory(lib)

add_executable(runAllTests
        testPawn.cpp
        testKnight.cpp
        testInput.cpp
        testChessBoard.cpp
        testRook.cpp)

target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        ${chessPiece}
        ${chessBoard}
        ${chessController}
        )

# What does this do exactly....
add_test(NAME AllTests COMMAND runAllTests)
