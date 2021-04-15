cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES Mandelbrot.cc)
add_executable(cpp ${SOURCE_FILES})
SET(CMAKE_CXX_FLAGS "-lpthread")
