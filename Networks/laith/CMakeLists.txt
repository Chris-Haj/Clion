cmake_minimum_required(VERSION 3.24)
project(laith C)

set(CMAKE_C_STANDARD 11)

add_executable(laith server.c threadpool.c threadpool.h)
