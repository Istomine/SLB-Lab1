cmake_minimum_required(VERSION 3.20)
project(SLB_Lab1 C)

set(CMAKE_C_STANDARD 23)

add_executable(SLB_Lab1 main.c
        decrypt0.c
        decrypt0.h
        decrypt2.c
        decrypt2.h
        decrypt1.c
        decrypt1.h
)
