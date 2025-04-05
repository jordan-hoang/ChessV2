set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_subdirectory(lib)

add_executable(runAllTests
        testPawn.cpp
        testKnight.cpp
        testInput.cpp
        testChessBoard.cpp
        testRook.cpp)

target_link_libraries(runAllTests
        PRIVATE
                gmock
                gtest
                gtest_main
                chessPiece
                chessBoard
                chessController
        )

add_test(NAME AllTests COMMAND runAllTests)
