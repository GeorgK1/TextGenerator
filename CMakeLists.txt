cmake_minimum_required(VERSION 3.20)
project(MarkovChains)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(MarkovChains
        include/markovchains.h
        include/split.h
        src/main.cpp
        src/markovchains.cpp
        src/split.cpp)
