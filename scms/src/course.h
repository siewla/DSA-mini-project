#include<iostream>
#include "studentlist.h"
#ifndef SCMS_COURSE_H
#define SCMS_COURSE_H
using std::string;


class Course {
private:
    string courseName;
    string courseCode;
    int courseSlots;
    int courseCreditHours;
    StudentList students;
    StudentList waitlist;

public:
    Course(string courseName, string courseCode, int courseSlots, int courseCreditHours, StudentList students, StudentList waitlist);
    string getCourseName();
    string getCourseCode();
    int getCourseSlots();
    int getCourseCreditHours();
    int checkAvailability();
    StudentList getStudents();
    StudentList getWaitlist();
    void enrollStudent(Student student);
    void dropStudent(int matrixNumber);
};


#endif //SCMS_COURSE_H
