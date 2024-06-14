#ifndef SCMS_STUDENTLIST_H
#define SCMS_STUDENTLIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "student.h" // get Student class reference

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::setw;

struct StudentNode { // struct for singly linked list
    Student student;
    StudentNode* next;
    // Constructor for StudentNode
    StudentNode(const Student& student, StudentNode* nextNode = nullptr)
            : student(student), next(nextNode) {}
};

class StudentList { // studentlist class obj
private:
    StudentNode* head;
    StudentNode* tail;
    int size;

public:
    // constructor
    StudentList();

    // main functions
    bool addStudent(Student& student);
    bool deleteStudent(int matrixNumber);
    bool deleteAllStudents();

    // enhancements
    void printStudents();
    void loadStudentsFromFile();
    bool uniqueStudent(Student& student);

    // getter
    Student* getStudent(int matrixNumber); 
    StudentNode* getHead();
    StudentNode* getTail();
    int getSize(); 

};

#endif //SCMS_STUDENTLIST_H


