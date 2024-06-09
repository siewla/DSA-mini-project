#include "studentList.h"
#include "student.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::setw;

StudentList::StudentList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


void StudentList::addStudent(Student student) {
    StudentNode* newNode = new StudentNode(student, nullptr);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

void StudentList::printStudents() {
    if (head == nullptr) {
        std::cout << "No students in the list" << std::endl;
    } else {
        StudentNode* current = head;
        // Print the header with column width
        cout << setw(15) << "Matrix Number" << setw(30)  << "Name" << setw(40)  << "Email" << endl;
        while (current != nullptr) {
            cout  << setw(15) << current->student.getMatrixNumber() << setw(30)<< current->student.getName() << setw(40) << current->student.getStudentEmail() << endl;
            current = current->next;
        }
    }
}

void StudentList::loadStudentsFromFile() {
    // get absolute path of the file
    std::ifstream file("../src/students.txt");
    if (!file) {
        std::cout << "Error opening file" << std::endl;
    } else {
        string line;
        while (getline(file, line)) {
            int pos = line.find(",");
            int studentMatrixNumber = stoi(line.substr(0, pos));
            string studentName = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
            string studentEmail = line.substr(line.find(",", pos + 1) + 1);
            Student student = Student(studentMatrixNumber, studentName, studentEmail);
            addStudent(student);
        }
        file.close();
    }
}

int StudentList::getSize() {
    return size;
}

StudentNode* StudentList::getHead() {
    return head;
}

void StudentList::deleteStudent(int matrixNumber) {
    StudentNode* current = head;
    StudentNode* previous = nullptr;

    while (current != nullptr) {
        if (current->student.getMatrixNumber() == matrixNumber) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void StudentList::deleteAllStudents() {
    StudentNode* current = head;
    StudentNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    size = 0;
}

// return student object or null
//Student* getStudent(int matrixNumber);

Student* StudentList::getStudent(int matrixNumber) {
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->student.getMatrixNumber() == matrixNumber) {
            return &current->student;
        }
        current = current->next;
    }
    return nullptr;
}



