#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
#include "course.h"
#include <vector>
#include <string>

class CourseManager
{
private:
    vector<Course> courses;
    int nextId = 1;

public:
    CourseManager();

    void addCourse(const string &name, const string &description); //dla admina
    bool enrollToCourse(int courseId, const string &nick); //dla studenta
};

#endif // COURSEMANAGER_H
