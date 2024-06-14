#ifndef SCMS_COURSELIST_H
#define SCMS_COURSELIST_H

#include <iostream>
#include "course.h"
#include "studentList.h"

using std::string;
using std::cout;
using std::endl;
using std::to_string;

struct courseNode { // struct 
    Course course;
    courseNode* next;
    courseNode(const Course& course, courseNode* nextNode = nullptr)
            : course(course), next(nextNode) {}
};

class CourseList { //courselist class obj
private:
    courseNode* head;
    courseNode* tail;
    int size;

public:
    // constructor
    CourseList();

    // main functions
    bool addCourse(Course& course);
    bool deleteCourse(string courseCode);
    bool deleteAllCourses();
    Course* findCourse(string courseCode);

    // enhancements 
    void printCourses();
    void loadCoursesFromFile();
    bool uniqueCourse(Course& course);
};


#endif //SCMS_COURSELIST_H


