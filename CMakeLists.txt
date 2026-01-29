cmake_minimum_required(VERSION 3.10)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

# ====================== Static Linking Configuration ======================
if(MSVC)
        # Force static MSVC runtime
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        add_compile_options(
                /GS           # Buffer security check
                /sdl          # Additional security checks
                /W3           # Warning level 3
                /permissive-  # Standards-conformant mode
        )

        set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO /LTCG")
else()
        # MinGW/GCC flags
        add_compile_options(
                -static
                -static-libgcc
                -static-libstdc++
        )
endif()

# ====================== Find Dependencies ======================
find_package(Boost REQUIRED COMPONENTS system)
add_definitions(-D_WIN32_WINNT=0x0601)

# ====================== Main Executable ======================
add_executable(ChessV2 main.cpp)

# Modern alternative to add_definitions()
target_compile_definitions(ChessV2 PRIVATE _WIN32_WINNT=0x0601)

target_link_libraries(ChessV2
        PUBLIC
                chessController
                Boost::system
                Boost::headers
        PRIVATE
                $<$<PLATFORM_ID:Windows>:ws2_32 mswsock>  # All Windows-specific libs
)

# ====================== Subdirectories ======================
add_subdirectory(test)
add_subdirectory(ChessNetwork)
add_subdirectory(ChessPiece)
add_subdirectory(ChessBoard)
add_subdirectory(ChessUtility)
add_subdirectory(ChessController)