CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
add_compile_options(-Wall -std=c++11)
PROJECT(homework5)
add_executable(hw5 src/homework5.cpp)
target_include_directories(hw5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

