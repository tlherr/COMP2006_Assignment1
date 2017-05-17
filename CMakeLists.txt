cmake_minimum_required(VERSION 3.7)
project(COMP2006_Assignment1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Materials.h Temperature.h Ass1-Boiling-ThomasHerr.h Assn1-TakeAway-ThomasHerr.h Assn1-BiNomialExpansion-ThomasHerr.h)
add_executable(COMP2006_Assignment1 ${SOURCE_FILES})