cmake_minimum_required(VERSION 3.17)
project(final_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(final_project Header.h ServerMain.cpp ServerStub.cpp ServerStub.h ClientMain.cpp ClientMain.h ClientStub.cpp ClientStub.h)