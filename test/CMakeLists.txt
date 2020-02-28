add_subdirectory(lib)

add_executable(runAllTests
        testA.cpp
        testKnight.cpp
        )

target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        ${chessPiece}
        ${chessBoard}
)

add_test(NAME AllTests COMMAND runAllTests)
