cmake_minimum_required(VERSION 3.12)
project(twentyQuestions)

set(CMAKE_CXX_STANDARD 14)

add_executable(twentyQuestions main.cpp cmake-build-debug/funct.cpp cmake-build-debug/funct.h functions.cpp functions.h)