#include "courseList.h"

CourseList::CourseList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool CourseList::addCourse(Course& course) {
    /*
    add course to linked list
    */
    if (!this->uniqueCourse(course)) {
        return false;
    }

    courseNode* newNode = new courseNode(course, nullptr);

    if (head == nullptr) { // if empty, course becomes first element
        head = newNode;
        tail = newNode;
    } else { // else, course appends to the linked list
        tail->next = newNode;
        tail = newNode;
    }
    size++;
    return true;
}

bool CourseList::deleteCourse(string courseCode) {
    /*
    delete course to linked list based on courseCode
    */
    courseNode* current = head;
    courseNode* previous = nullptr;

    while (current != nullptr) {
        if (current->course.getCourseCode() == courseCode) { // condition
            if (previous == nullptr) { // first element
                head = current->next; // second element becomes first
                if (head == nullptr) {
                    tail = nullptr;
                }
            } else { // except first element
                previous->next = current->next; // link previous's next to current's next
                if (current == tail) { // if last element, tail should be second last element
                    tail = previous;
                }
            }
            delete current;
            size--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool CourseList::deleteAllCourses() {
    /*
    delete all course from linked list
    */
    courseNode* current = head;
    courseNode* next = nullptr;

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

    return true; // removed all courses
}

Course* CourseList::findCourse(string courseCode) {
    /*
    delete all course from linked list
    */
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
//    std::ifstream file(".\\src\\courses.txt");
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

bool CourseList::uniqueCourse(Course& course) {
    /*
    delete all course from linked list
    */
    courseNode* current = head;
    if (head != nullptr) {
        courseNode* current = head;
        while (current != nullptr) {
            if ((course.getCourseName() == current->course.getCourseName()) \
                || (course.getCourseCode() == current->course.getCourseCode())) {
                return false;
            }
            current = current->next;
        }
    }
    return true;
}



