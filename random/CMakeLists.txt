cmake_minimum_required(VERSION 3.22)
project(random C)

set(CMAKE_C_STANDARD 99)

add_executable(random matrix_mult1.c cmake-build-debug/matrix_mult2.c NumGenerator.c Runner.c)
