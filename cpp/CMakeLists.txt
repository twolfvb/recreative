cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Cachipun/Hand.h)
set(HEADER_FILES)
add_executable(cpp ${SOURCE_FILES})
include_directories(Cachipun)
