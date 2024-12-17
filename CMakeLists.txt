cmake_minimum_required(VERSION 3.29)
project(laba4 C)

set(CMAKE_C_STANDARD 11)

add_executable(laba4 main.c
        stack.h
        stack.c
        workwithfile.c
        workwithfile.h)
