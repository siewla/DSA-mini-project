#include <iostream>
#include "src/student.h"
#include "src/course.h"
#include "src/studentList.h"
#include "src/courseList.h"
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;

void registerStudent(StudentList& studentList) {
    int studentId;
    cout << "Enter student ID: ";
    cin >> studentId;

    string studentName;
    cout << "Enter student name: ";
    cin.ignore(); // to consume the newline character (Enter key)
    getline(cin, studentName); // to consume the newline character (Enter key

    string studentEmail;
    cout << "Enter student email: ";
    cin.ignore();
    getline(cin, studentEmail);

    cout <<"You have entered the following information: " << endl;
    cout << "Student ID    : " << studentId << endl;
    cout << "Student Name  : " << studentName << endl;
    cout << "Student Email : " << studentEmail << endl;
    Student newStudent(studentId, studentName, studentEmail);
    studentList.addStudent(newStudent);
    cout << "Student has been registered successfully" << endl;
}

int registerCourse() {
    string courseName;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, courseName);

    string courseCode;
    cout << "Enter course code: ";
    cin.ignore();
    getline(cin, courseCode);

    int courseSlots;
    cout << "Enter course slots: ";
    cin >> courseSlots;

    int courseCreditHours;
    cout << "Enter course credit hours: ";
    cin >> courseCreditHours;

    cout <<"You have entered the following information: " << endl;
    cout << "Course Name        : " << courseName << endl;
    cout << "Course Code        : " << courseCode << endl;
    cout << "Course Slots       : " << courseSlots << endl;
    cout << "Course Credit Hours: " << courseCreditHours << endl;

    Course courseToSave(courseName, courseCode, courseSlots, courseCreditHours, StudentList(), StudentList());

    cout << "Course has been registered successfully" << endl;
    return 0;
}

int printStudents(CourseList courseList) {
    cout << "Enter course code to view students: ";
    string courseCode;
    cin.ignore();
    // trim leading and trailing whitespaces
    getline(cin, courseCode);
    cout << "Course Code: " << courseCode << endl;
    Course* course = courseList.findCourse(courseCode);
    if (course != nullptr) {
        int studentSize = course->getStudents().getSize();
        if (studentSize == 0) {
            cout << "No students enrolled in this course" << endl;
        } else {
            cout << "Students enrolled in this course: " << endl;
            course->getStudents().printStudents();
        }
    } else {
        cout << "Course not found" << endl;
    }
    return 0;
}

int showStudentsMenu (Course* course, StudentList& studentList, string type) {
        cout << "1: Display current enrolled students" << endl;
        cout << "2: Display students in waitlist" << endl;
        if (type == "enroll") {
            cout << "3: Enroll student by matrix number" << endl;
        } else {
            cout << "3: De-enroll student by matrix number" << endl;
        }
        cout << "4: Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current Enrolled Students" << endl;
                course->getStudents().printStudents();
                return -1;
            case 2:
                cout << "Students in Waitlist" << endl;
                course->getWaitlist().printStudents();
                return -1;
            case 3: {
                cout << "Enter student matrix number: ";
                int matrixNumber;
                cin >> matrixNumber;
                Student *student = studentList.getStudent(matrixNumber);
                if (student == nullptr) {
                    cout << "Student not found" << endl;
                } else {
                    if (type == "de-enroll") {
                        course->dropStudent(matrixNumber);
                        cout << "Student de-enrolled successfully" << endl;
                    } else {
                        course->enrollStudent(*student);
                        cout << "Student enrolled successfully" << endl;
                    }
                }
                return -1;
            }
            case 4:
                cout << "Exit" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                return -1;
        }
};

int enrollStudent(StudentList& studentList, CourseList& courseList) {
    courseList.printCourses();
    cout << "Enter course code: ";
    string courseCode;
    cin.ignore();
    getline(cin, courseCode);
    Course* course = courseList.findCourse(courseCode);
    if (course == nullptr) {
        cout << "Course not found" << endl;
        return 0;
    }


    int choice = showStudentsMenu(course, studentList, "enroll");
    while (choice != 0) {
        choice = showStudentsMenu(course, studentList, "enroll");
    }

    return 0;
}

int deEnrollStudent(StudentList& studentList, CourseList& courseList) {
    courseList.printCourses();
    cout << "Enter course code: ";
    string courseCode;
    cin.ignore();
    getline(cin, courseCode);
    Course* course = courseList.findCourse(courseCode);
    if (course == nullptr) {
        cout << "Course not found" << endl;
        return 0;
    }

    int choice = showStudentsMenu(course, studentList, "de-enroll");
    while (choice != 0) {
        choice = showStudentsMenu(course, studentList, "de-enroll");
    }

    return 0;
}

void showMenu(StudentList& studentList, CourseList& courseList) {
    cout << "Please select an option:" << endl;
    cout << "1. Register a student" << endl;
    cout << "2. Register a course" << endl;
    cout << "3. Enroll a student" << endl;
    cout << "4. De-enroll a student" << endl;
    cout << "5. Display courses" << endl;
    cout << "6. Display students" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Register a student" << endl;
            registerStudent(studentList);
            showMenu(studentList, courseList);
            break;
        case 2:
            cout << "Register a course" << endl;
            registerCourse();
            showMenu(studentList, courseList);
            break;
        case 3:
            cout << "Enroll a student" << endl;
            enrollStudent(studentList, courseList);
            showMenu(studentList, courseList);
            break;
        case 4:
            cout << "De-enroll a student" << endl;
            deEnrollStudent(studentList, courseList);
            showMenu(studentList, courseList);
            break;
        case 5:
            cout << "Display courses" << endl;
            courseList.printCourses();
            printStudents(courseList);
            showMenu(studentList, courseList);
            break;
        case 6:
            cout << "Display All Students" << endl;
            studentList.printStudents();
            showMenu(studentList, courseList);
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            showMenu(studentList, courseList);
            break;
    }
}

int main() {
    StudentList studentList;
    CourseList courseList;
    studentList.loadStudentsFromFile();
    courseList.loadCoursesFromFile();
    showMenu(studentList, courseList);
    return 0;
}
