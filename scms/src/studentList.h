#include <iostream>
#include <fstream>
#include "student.h"
#ifndef SCMS_STUDENTLIST_H
#define SCMS_STUDENTLIST_H

using std::string;

struct StudentNode {
    Student student;
    StudentNode* next;
    // Constructor for StudentNode
    StudentNode(const Student& student, StudentNode* nextNode = nullptr)
            : student(student), next(nextNode) {}
};

class StudentList {
private:
    StudentNode* head;
    StudentNode* tail;
    int size;

public:
    StudentList();
    void addStudent(Student student);
    void loadStudentsFromFile();
    void printStudents();
    StudentNode* getHead();
    // return student object or null
    Student* getStudent(int matrixNumber);
    void deleteStudent(int matrixNumber);
    void deleteAllStudents();
    int getSize();
};

#endif //SCMS_STUDENTLIST_H


