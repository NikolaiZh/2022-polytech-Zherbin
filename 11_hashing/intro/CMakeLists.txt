cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(HashF LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include(doctest.cmake)
add_executable(a.out test_hash.cpp)
target_link_libraries(a.out PRIVATE doctest)

