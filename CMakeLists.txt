cmake_minimum_required(VERSION 3.20)
project(Cpp_Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Cpp_Algorithms
        Arrays.h
        LinkedList.h
        main.cpp
        Stack.h Queue.h ArrayDict.h HashDict.h Entry.h)
