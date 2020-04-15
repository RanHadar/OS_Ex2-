cmake_minimum_required(VERSION 3.15)
project(Ex2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex2 main.cpp uthreads.cpp uthreads.h Scheduler.cpp Scheduler.h Thread.cpp Thread.h)