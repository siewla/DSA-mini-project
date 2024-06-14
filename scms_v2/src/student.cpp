#include "student.h"

Student::Student(
    int matrixNumber,
    string name,
    string studentEmail
    ): matrixNumber(matrixNumber), name(name), studentEmail(studentEmail) {

    if (!this->validEmail(studentEmail)) {
        throw std::invalid_argument("Invalid email address."); // don't build if email address is invalid.
    }
}

bool Student::validEmail(string& email) {
    /*
    email must consist of '@' and no space in it. 
    */
    if (!(email.find('@') != string::npos)) {
        return false;
    }
    for (char ch : email) {
        if (ch == ' ') {
            return false;
        }
    }
    return true;
}


int Student::getMatrixNumber() const {
    return matrixNumber;
}

string Student::getName() const {
    return name;
}

string Student::getStudentEmail() const {
    return studentEmail;
}




