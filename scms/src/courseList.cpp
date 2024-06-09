#include "courseList.h"
#include "studentList.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::to_string;

CourseList::CourseList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


void CourseList::addCourse(Course course) {
    courseNode* newNode = new courseNode(course, nullptr);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

void CourseList::printCourses() {
    if (head == nullptr) {
       cout << "No courses in the list" << endl;
    } else {
        courseNode* current = head;
        cout << setw(40) << "Course Name" << setw(20) << "Course Code" << setw(30) << "Slots (available/total)" << setw(20) << "Credit Hours" << endl;
        while (current != nullptr) {
            string occupiedOverSlotsRatio = to_string(current->course.getStudents().getSize()) + "/" + to_string(current->course.getCourseSlots());
            cout << std::setw(40) << current->course.getCourseName()
                << setw(20) << current->course.getCourseCode()
                << setw(30) << occupiedOverSlotsRatio
                << std::setw(20) << current->course.getCourseCreditHours() << std::endl;
            current = current->next;
        }
    }
}

void CourseList::loadCoursesFromFile() {
    std::ifstream file("../src/courses.txt");
    if (!file) {
        std::cout << "Error opening file" << std::endl;
    } else {
        string line;
        while (getline(file, line)) {
            int pos = line.find(",");
            string courseName = line.substr(0, pos);
            string courseCode = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
            int courseSlots = stoi(line.substr(line.find(",", pos + 1) + 1, line.find(",", line.find(",", pos + 1) + 1) - line.find(",", pos + 1) - 1));
            int courseCreditHours = stoi(line.substr(line.find(",", line.find(",", pos + 1) + 1) + 1));

            StudentList students;
            StudentList waitlist;
            Course course = Course(courseName, courseCode, courseSlots, courseCreditHours, students, waitlist);
            addCourse(course);
        }
        file.close();
    }
}

Course* CourseList::findCourse(string courseCode) {
    courseNode* current = head;
    cout << "Finding course with code: " << courseCode << endl;
    while (current != nullptr) {
        if (current->course.getCourseCode() == courseCode) {
            return &current->course;
        }
        current = current->next;
    }
    return nullptr;
}

void CourseList::deleteCourse(string courseCode) {
    courseNode* current = head;
    courseNode* previous = nullptr;
    while (current != nullptr) {
        if (current->course.getCourseCode() == courseCode) {
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

void CourseList::deleteAllCourses() {
    courseNode* current = head;
    while (current != nullptr) {
        courseNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}




