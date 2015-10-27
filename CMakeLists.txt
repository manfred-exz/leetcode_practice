cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(spiral_matrix spiral_matrix.cpp)
add_executable(spiral_matrix_ii spiral_matrix_ii.cpp)
add_executable(simplify_path simplify_path.cpp)
add_executable(3sum_closest 3sum_closest.cpp)
add_executable(two_sum two_sum.cpp)
