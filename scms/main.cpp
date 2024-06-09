#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int registerStudent() {
    // get student name, id, and email
    // create a student object

    double studentId;
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

    cout << "Student has been registered successfully" << endl;
    return 0;
}

int registerCourse() {
    // get course name, code, number of slots and credit hours
    // create a course object
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

    cout << "Course has been registered successfully" << endl;
    return 0;
}

int showMenu() {
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
            registerStudent();
            showMenu();
            break;
        case 2:
            cout << "Register a course" << endl;
            registerCourse();
            showMenu();
            break;
        case 3:
            cout << "Enroll a student" << endl;
            break;
        case 4:
            cout << "De-enroll a student" << endl;
            break;
        case 5:
            cout << "Display courses" << endl;
            break;
        case 6:
            cout << "Display students" << endl;
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            showMenu();
            break;
    }
}

int main() {
    showMenu();
    return 0;
}


//1. Linked list for courses and students
//2. new feature: waiting list - queue

//1. Register an student
//2. Register a course (with limit)
//3. Enroll a student (over limit can do wait list)
//4. De-enroll a student (if any student in wait list, enroll the student on first of the queue)
//5. display courses
//6. display students