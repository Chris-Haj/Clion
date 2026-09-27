cmake_minimum_required(VERSION 3.24)
project(wis)

set(CMAKE_CXX_STANDARD 17)

add_executable(wis main.cpp MathQuiz.cpp MathQuiz.h Exercise.cpp Exercise.h ExGenerator.cpp ExGenerator.h)
