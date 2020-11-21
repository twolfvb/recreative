cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Cachipun/Hand.h Cachipun/Hand.cpp Tree/TreeNode.h Tree/TreeNode.cpp mandelbrot.cpp)
set(HEADER_FILES Tree/TreeNode.h)
add_executable(cpp ${SOURCE_FILES})
include_directories(Cachipun Tree)
