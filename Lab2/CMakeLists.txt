cmake_minimum_required(VERSION 3.19)
project(2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2
        University.cpp
        University.h
    main.cpp
    Tree.cpp
    Tree.h)
