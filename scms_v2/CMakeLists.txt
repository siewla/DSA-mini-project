#cmake_minimum_required(VERSION 3.28)
project(scms_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(scms main.cpp
        src/student.cpp
        src/student.h
        src/course.cpp
        src/course.h
        src/studentList.cpp
        src/studentList.h
        src/courseList.cpp
        src/courseList.h
        src/courses.txt
        src/students.txt
)
