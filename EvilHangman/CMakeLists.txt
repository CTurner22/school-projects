cmake_minimum_required(VERSION 3.10)
project(hangman)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hangman
        main.cpp
        hangman.cpp
        hangman.h)
