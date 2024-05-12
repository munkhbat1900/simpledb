cmake_minimum_required(VERSION 3.29.2)
project(simpledb)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "clang++ compiler" FORCE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simpledb main.cpp)

###############
# Testing
###############

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    example_tests
    example_tests.cpp
)
target_link_libraries(
    example_tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(example_tests)
