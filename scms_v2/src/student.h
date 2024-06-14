#ifndef SCMS_STUDENT_H
#define SCMS_STUDENT_H

#include <iostream>
#include <fstream>

using std::string;
//using std::ofstream;
//using std::cout;
//using std::endl;
//using std::ios;

class Student { // class obj for storing student data
private:
    int matrixNumber; 
    string name;
    string studentEmail;

public:
    // constructor
    Student(int matrixNumber, string name, string studentEmail);

    // enhancements
    bool validEmail(string& email);

    // getter
    int getMatrixNumber() const;
    string getName() const;
    string getStudentEmail() const;


};

#endif //SCMS_STUDENT_H
