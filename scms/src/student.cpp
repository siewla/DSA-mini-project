#include "student.h"
#include <fstream>
#include <iostream>

using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios;

Student::Student(
    int matrixNumber,
    string name,
    string studentEmail
    ): matrixNumber(matrixNumber), name(name), studentEmail(studentEmail) {}


int Student::getMatrixNumber() {
    return matrixNumber;
}

string Student::getName() {
    return name;
}

string Student::getStudentEmail() {
    return studentEmail;
}
