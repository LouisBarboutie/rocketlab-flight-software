cmake_minimum_required(VERSION 3.16)
project(Exercise1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB HEADERS CONFIGURE_DEPENDS inc/*.hpp)

add_executable(exercise1 ${SOURCES} ${HEADERS})

target_include_directories(exercise1 PRIVATE inc)

target_compile_options(exercise1 PRIVATE
-Wall -Wextra -Wpedantic -Wconversion
)
