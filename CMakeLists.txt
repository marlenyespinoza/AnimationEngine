cmake_minimum_required(VERSION 4.3)
project(AnimationEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnimationEngine main.cpp
        ActionQueue.h
        ActionQueue.cpp
        UndoStack.h)
