#include "course.h"
#include <iostream>
using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios;

Course::Course(string courseName, string courseCode, int courseSlots, int courseCreditHours, StudentList students, StudentList waitlist)
        : courseName(courseName),
          courseCode(courseCode),
          courseSlots(courseSlots),
          courseCreditHours(courseCreditHours),
          students(students),
          waitlist(waitlist) {
}

string Course::getCourseName() {
    return courseName;
}

string Course::getCourseCode() {
    return courseCode;
}

int Course::getCourseSlots() {
    return courseSlots;
}

int Course::getCourseCreditHours() {
    return courseCreditHours;
}

int Course::checkAvailability() {
    return courseSlots - students.getSize();
}

StudentList Course::getStudents() {
    return students;
}

StudentList Course::getWaitlist() {
    return waitlist;
}

void Course::enrollStudent(Student student) {
    if (students.getSize() < courseSlots) {
        students.addStudent(student);
    } else {
        waitlist.addStudent(student);
    }
}

void Course::dropStudent(int matrixNumber) {
    students.deleteStudent(matrixNumber);
    if (waitlist.getSize() > 0) {
        Student student = waitlist.getHead()->student;
        students.addStudent(student);
        waitlist.deleteStudent(student.getMatrixNumber());
    }
}
