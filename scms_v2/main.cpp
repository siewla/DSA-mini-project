#include <iostream>
#include "src/student.h"
#include "src/course.h"
#include "src/studentList.h"
#include "src/courseList.h"
//#include "iomanip"
#include <fstream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;

/**
TODO
1. error handing so the app not running indefinitely
2. add individual proper flow chart 
3. test the flow and cover the bugs
4. finish the report
**/

// Helper function to convert string to uppercase
string toUpperCase(const string& str) {
    string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

void registerStudent(StudentList& studentList) {
    // get student id, name, email and save it to "Student"
    int studentId;
    cout << "Enter student ID: ";
    while (!(cin >> studentId) || cin.peek() != '\n') {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Enter an integer: ";
    }

    string studentName;
    cout << "Enter student name: ";
    cin.ignore(); // to consume the newline character (Enter key)
    getline(cin, studentName); // to consume the newline character (Enter key)

    string studentEmail;
    cout << "Enter student email: ";
    cin.ignore();
    getline(cin, studentEmail);

    cout <<"You have entered the following information: " << endl;
    cout << "Student ID    : " << studentId << endl;
    cout << "Student Name  : " << studentName << endl;
    cout << "Student Email : " << studentEmail << endl;

    try { // to make sure Student inputs are correct
        Student newStudent(studentId, studentName, studentEmail);
        studentList.addStudent(newStudent);
        cout << "Student has been registered successfully" << endl;
    } catch (...) {
        cout << "bad student obj\n";
    }
}

void registerCourse(CourseList& courseList) {
    // get course name, code, slot, credit hours and save it to "Course"
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
    while (!(cin >> courseSlots) || cin.peek() != '\n') {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Enter an integer: ";
    }

    int courseCreditHours;
    cout << "Enter course credit hours: ";
    while (!(cin >> courseCreditHours) || cin.peek() != '\n') {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Enter an integer: ";
    }

    cout <<"You have entered the following information: " << endl;
    cout << "Course Name        : " << courseName << endl;
    cout << "Course Code        : " << toUpperCase(courseCode) << endl;
    cout << "Course Slots       : " << courseSlots << endl;
    cout << "Course Credit Hours: " << courseCreditHours << endl;

    try { // to make sure Course inputs are correct
        Course newCourse(courseName, toUpperCase(courseCode), courseSlots, courseCreditHours, StudentList(), StudentList());
        courseList.addCourse(newCourse);
        cout << "Course has been registered successfully" << endl;
    } catch (...) {
        cout << "bad Course obj\n";
    }
}

int printStudents(CourseList courseList) {
    // insert code and print students
    cout << "Enter course code to view students: ";
    string courseCode;
    cin.ignore();
    // trim leading and trailing whitespaces
    getline(cin, courseCode);
    courseCode = toUpperCase(courseCode);
    
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
    while (!(cin >> choice) || cin.peek() != '\n') {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Enter an integer: ";
    }

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
            while (!(cin >> matrixNumber) || cin.peek() != '\n') {
                std::cout << "Invalid input. Please enter an integer." << std::endl;
                std::cin.clear(); // Clear the fail state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Enter an integer: ";
            }
            Student *student = studentList.getStudent(matrixNumber);
            if (student == nullptr) {
                cout << "Student not found" << endl;
            } else {
                if (type == "de-enroll") { 
                    // find if it exists in stundetlist and awitlist
                    if (course->dropStudent(matrixNumber)) {
                        cout << "Student de-enrolled successfully" << endl;
                    }
                    //course->getStudents().printStudents();
                    //course->getWaitlist().printStudents();

                } else { // enroll
                    if (course->enrollStudent(*student)) {
                        cout << "Student enrolled successfully" << endl; 
                    }
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
    courseCode = toUpperCase(courseCode);
    
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
    courseCode = toUpperCase(courseCode);
    
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

    int choice;

    while (true) { // need to make sure the input is correct
        cout << "Please select an option:" << endl;
        cout << "1. Register a student" << endl;
        cout << "2. Register a course" << endl;
        cout << "3. Enroll a student" << endl;
        cout << "4. De-enroll a student" << endl;
        cout << "5. Display courses" << endl;
        cout << "6. Display students" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << std::endl;
            continue;
        }
        break;
    }

    switch (choice) {
        case 1:
            cout << "Register a student" << endl;
            registerStudent(studentList);
            showMenu(studentList, courseList);
            break;
        case 2:
            cout << "Register a course" << endl;
            registerCourse(courseList);
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
    // setup
    StudentList studentList;
    CourseList courseList;
    studentList.loadStudentsFromFile();
    courseList.loadCoursesFromFile();
    studentList.printStudents();
    courseList.printCourses();

    // main
    showMenu(studentList, courseList);
    return 0;
}





