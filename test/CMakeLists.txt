add_subdirectory(lib)

add_executable(runAllTests
        testA.cpp
        testKnight.cpp
        testInput.cpp)

target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        ${chessPiece}
        ${chessBoard}
        ${chessController}
        )

add_test(NAME AllTests COMMAND runAllTests)
