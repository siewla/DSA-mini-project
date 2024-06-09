cmake_minimum_required(VERSION 3.28)
project(scms)

set(CMAKE_CXX_STANDARD 20)

add_executable(scms main.cpp
        src/student.cpp
        src/student.h
        src/course.cpp
        src/course.h
        src/registration.cpp
        src/registration.h)
