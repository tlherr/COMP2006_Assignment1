cmake_minimum_required(VERSION 3.7)
project(COMP2006_Assignment1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Ass1-Boiling-ThomasHerr.cpp Materials.h Temperature.h)
add_executable(COMP2006_Assignment1 ${SOURCE_FILES})