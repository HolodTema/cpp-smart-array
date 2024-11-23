cmake_minimum_required(VERSION 2.8)

project(SmartArray)

set(SOURCE_EXE main.cpp)

add_executable(main ${SOURCE_EXE} SmartArray.h SmartArray.cpp)
