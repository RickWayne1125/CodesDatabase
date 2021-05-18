cmake_minimum_required(VERSION 3.10)
project(toy_compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(toy_compiler main.cpp tokens.h tokens.l tokens.h LexAnalysis.cpp SyntaxAnalysis.cpp productions.h)