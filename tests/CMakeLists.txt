cmake_minimum_required(VERSION 3.10)
project(HelloTest)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(hello_test hello_test.cpp)
target_link_libraries(hello_test ${GTEST_LIBRARIES} pthread)

add_test(NAME HelloTest COMMAND hello_test)