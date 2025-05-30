#include "coursemanager.h"

CourseManager::CourseManager() {}

void CourseManager::addCourse(const string &name, const string &description)
{
    courses.emplace_back(nextId++, name, description);
}

bool CourseManager::enrollToCourse(int courseId, const string &nick)
{
    for (auto i = courses.begin(); i != courses.end(); ++i) {
        if (i->getId() == courseId) {
            if (!i->isStudentEnrolled(nick)) {
                i->enrollStudent(nick);
                return true;  // zapisano studenta
            } else {
                return false;
            }
        }
    }
    return false;
}
