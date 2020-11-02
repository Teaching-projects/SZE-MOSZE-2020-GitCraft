cmake_minimum_required(VERSION 2.6)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link test_parser with what we want to test 
# and the GTest and pthread library
add_library(testCode ../parser.cpp)
add_library(testCode ../character.cpp)
add_executable(test_parser test_parser.cpp)

target_link_libraries(test_parser ${GTEST_LIBRARIES} pthread testCode)