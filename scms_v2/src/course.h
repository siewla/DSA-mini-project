#ifndef SCMS_COURSE_H
#define SCMS_COURSE_H

#include<iostream>
#include "studentList.h" // require StudentList reference

using std::string;
//using std::ofstream;
//using std::cout;
//using std::endl;
//using std::ios;

class Course {
private:
    string courseName;
    string courseCode;
    int courseSlots;
    int courseCreditHours;
    StudentList students;
    StudentList waitlist;

public:
    // constructor
    Course(string courseName, string courseCode, int courseSlots, int courseCreditHours, StudentList students, StudentList waitlist);

    // main functions
    bool enrollStudent(Student& student);
    bool dropStudent(int matrixNumber);

    // getter
    string getCourseName();
    string getCourseCode();
    int getCourseSlots();
    int getCourseCreditHours();
    StudentList getStudents();
    StudentList getWaitlist();
};


#endif //SCMS_COURSE_H
