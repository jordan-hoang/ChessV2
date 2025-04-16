cmake_minimum_required(VERSION 3.10)
project(ChessV2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

# ====================== Static Linking Configuration ======================
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT "C:/Boost")
set(BOOST_INCLUDEDIR "C:/Boost/include/boost-1_87")
set(BOOST_LIBRARYDIR "C:/Boost/lib")
set(CMAKE_GENERATOR_PLATFORM x64)

if(MSVC)
        # Force static MSVC runtime
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

        # Additional compiler flags
        add_compile_options(
                /GS           # Buffer security check
                /sdl          # Additional security checks
                /W4           # Warning level 4
                /permissive-  # Standards-conformant mode
                /MT          # FORCE STATIC LINKING FOR EASY RELEASE....
        )

        # Linker flags
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

target_include_directories(ChessV2
        PUBLIC
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(ChessV2
        PUBLIC
                chessController
                $<$<BOOL:${Boost_SYSTEM_FOUND}>:Boost::system>
        PRIVATE
                $<$<PLATFORM_ID:Windows>:ws2_32 mswsock>  # All Windows-specific libs
)

# ====================== Subdirectories ======================
add_subdirectory(test)
add_subdirectory(ChessNetwork)
add_subdirectory(ChessPiece)
add_subdirectory(ChessBoard)
add_subdirectory(ChessController)
add_subdirectory(ChessUtility)