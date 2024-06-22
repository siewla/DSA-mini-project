#include "course.h"

Course::Course(string courseName, string courseCode, int courseSlots, int courseCreditHours, StudentList students, StudentList waitlist)
        : courseName(courseName),
          courseCode(courseCode),
          courseSlots(courseSlots),
          courseCreditHours(courseCreditHours),
          students(students),
          waitlist(waitlist) {
}

bool Course::enrollStudent(Student& student) {
    /*
    add student to course
    */
    if (students.getSize() < courseSlots) {
        students.addStudent(student); // add to slot if has empty slot
    } else {
        waitlist.addStudent(student); // else, place to waiting list
    }
    return true;
}

bool Course::dropStudent(int matrixNumber) { // dropping student from student list or waiting list
    /*
    drop student from course
    */
    if (students.getStudent(matrixNumber) != nullptr) { // found in student list
        students.deleteStudent(matrixNumber);
        if (waitlist.getSize() > 0) { // move wait list element to student list
            Student student = waitlist.getHead()->student;
            students.addStudent(student);
            waitlist.deleteStudent(student.getMatrixNumber());
        }
    }
    else if (waitlist.getStudent(matrixNumber) != nullptr) {
        waitlist.deleteStudent(matrixNumber);
    }
    else {
        std::cout << "student did not apply to the course\n";
        return false;
    }
    return true;
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

StudentList Course::getStudents() { // return studentlist class obj
//    std::cout << "student size is " << students.getSize() << "\n"; -> for debugging purposes
    return students;
}

StudentList Course::getWaitlist() { // return waiting list class obj
//    std::cout << "waitlist size is " << waitlist.getSize() << "\n"; -> for debugging purposes
    return waitlist;
}



