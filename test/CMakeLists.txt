add_subdirectory(lib)

add_executable(runAllTests
        testA.cpp
        )

target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        ${chessPiece}
)

add_test(NAME AllTests COMMAND runAllTests)
