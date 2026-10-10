cmake_minimum_required(VERSION 3.16)
project(Exercise1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exercise1
main.cpp
BinarySearch.cpp
Interpolate.cpp
CalculatePressure.cpp
)

target_compile_options(exercise1 PRIVATE
-Wall -Wextra -Wpedantic -Wconversion
)
