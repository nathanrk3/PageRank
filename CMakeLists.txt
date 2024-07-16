cmake_minimum_required(VERSION 3.27)
project(pagerank)

set(CMAKE_CXX_STANDARD 14)

add_executable(pagerank main.cpp
        graph.h
        graph.cpp)
