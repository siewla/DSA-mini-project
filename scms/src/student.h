
#include <iostream>
using std::string;
#ifndef SCMS_STUDENT_H
#define SCMS_STUDENT_H

class Student {
private:
    int matrixNumber;
    string name;
    string studentEmail;

public:
    Student(int matrixNumber, string name, string studentEmail);
    int getMatrixNumber();
    string getName();
    string getStudentEmail();
};

#endif //SCMS_STUDENT_H
