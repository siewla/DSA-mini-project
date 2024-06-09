#include <iostream>
#include "course.h"

#ifndef SCMS_COURSELIST_H
#define SCMS_COURSELIST_H
using std::string;


struct courseNode {
    Course course;
    courseNode* next;
    courseNode(const Course& course, courseNode* nextNode = nullptr)
            : course(course), next(nextNode) {}
};

class CourseList {
private:
    courseNode* head;
    courseNode* tail;
    int size;

public:
    CourseList();
    void addCourse(Course course);
    void loadCoursesFromFile();
    void printCourses();
    Course* findCourse(string courseCode);
    void deleteCourse(string courseCode);
    void deleteAllCourses();
};


#endif //SCMS_COURSELIST_H


