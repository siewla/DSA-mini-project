#include "studentList.h"


StudentList::StudentList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


bool StudentList::addStudent(Student& student) {
    /*
    add student node to the linked list
    */

    if (!this->uniqueStudent(student)) { // if not unique student, stop adding process
        return false;
    }

    StudentNode* newNode = new StudentNode(student, nullptr); // create new node 

    if (head == nullptr) { // if empty, node becomes first element
        head = newNode; 
        tail = newNode;
    } else {
        tail->next = newNode; // else, node appends to the linked list
        tail = newNode;
    }
    size++;

    return true;
}

bool StudentList::deleteStudent(int matrixNumber) {
    /*
    search and delete student node based on matrix number
    */
    StudentNode* current = head;
    StudentNode* previous = nullptr;

    while (current != nullptr) {
        if (current->student.getMatrixNumber() == matrixNumber) { // condition
            if (previous == nullptr) { // first element
                head = current->next; // second element becomes first
                if (head == nullptr) { // if secone elemenet is nullptr, tail should also be nullptr
                    tail = nullptr;
                }
            } else { // except first element
                previous->next = current->next; // link previous's next to current's next
                if (current == tail) { // if last element, tail should be second last element
                    tail = previous;
                }
            }
            delete current;
            std::cout << "student deleted\n";
            size--;
            return true; // if successfully removed
        }
        previous = current;
        current = current->next;
    }
    return false; // if not able to remove
}

bool StudentList::deleteAllStudents() {
    /*
    delete all elements in linked list
    */
    StudentNode* current = head;
    StudentNode* next = nullptr;

    if (current == nullptr) {
        return false; // nothing to remove
    }
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;

    return true; // removed all students
}

bool StudentList::uniqueStudent(Student& student) {
    /*
    compare new student with the list elements, only unique student is accepted
    */
    StudentNode* current = head;
    if (head != nullptr) {
        StudentNode* current = head;
        while (current != nullptr) {
            if ((student.getMatrixNumber() == current->student.getMatrixNumber()) \
                || (student.getName() == current->student.getName())) { // don't care email similarity
                return false;
            }
            current = current->next; // iterate through linked list
        }
    }
    return true;
}

void StudentList::printStudents() {
    /*
    print students in linked list
    */
    if (head == nullptr) {
        std::cout << "No students in the list" << std::endl;
    } else {
        StudentNode* current = head;
        // Print the header with column width
        cout << setw(15) << "Matrix Number" << setw(30)  << "Name" << setw(40)  << "Email" << endl;
        while (current != nullptr) {
            cout  << setw(15) << current->student.getMatrixNumber() << setw(30)<< current->student.getName() << setw(40) << current->student.getStudentEmail() << endl;
            current = current->next; // iterate through linked list
        }
    }
}

void StudentList::loadStudentsFromFile() {
    /*
    get data from file
    */
    // get absolute path of the file
    //std::ifstream file("../src/students.txt"); // mac
    std::ifstream file(".\\src\\students.txt"); // windows
    if (!file) {
        std::cout << "Error opening file" << std::endl;
    } else {
        string line;
        while (getline(file, line)) {
            int pos = line.find(",");
            int studentMatrixNumber = stoi(line.substr(0, pos));
            string studentName = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
            string studentEmail = line.substr(line.find(",", pos + 1) + 1);
            Student student = Student(studentMatrixNumber, studentName, studentEmail); // new class obj
            addStudent(student); // add to linked list
        }
        file.close();
    }
}


StudentNode* StudentList::getHead() {
    return head; // return first element of linked list
}

StudentNode* StudentList::getTail() {
    return tail; // return last element of linked list
}

Student* StudentList::getStudent(int matrixNumber) { // get student based on matrix number
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->student.getMatrixNumber() == matrixNumber) {
            return &current->student;
        }
        current = current->next;
    }
    return nullptr;
}

int StudentList::getSize() { // get linked list size
    return size;
}







