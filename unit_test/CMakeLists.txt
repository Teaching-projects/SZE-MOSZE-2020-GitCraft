cmake_minimum_required(VERSION 3.10)

project(Unit_test_GitCraft)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
<<<<<<< HEAD
get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR})

file(GLOB TEST_SOURCES ./*.cpp)
file(GLOB SOURCES ../*.cpp)

list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp") 
=======
# Link test_parser with what we want to test 
# and the GTest and pthread library
add_library(testCode ../parser.cpp ../character.cpp)
add_executable(test_parser test_parser.cpp)
>>>>>>> master

add_executable(test_parser ${TEST_SOURCES} ${SOURCES})
target_compile_features(test_parser PRIVATE cxx_std_17)
target_link_libraries(test_parser ${GTEST_LIBRARIES} pthread)