#include "coursemanager.h"

CourseManager::CourseManager() {}

void CourseManager::addCourse(const User* user, const QString &name, const QString &description)
{
    if (!user || !user->isAdmin()) {
        throw std::runtime_error("Tylko administrator może dodawać kursy");
    }


    courses.emplace_back(nextId++, name, description);
}

bool CourseManager::enrollToCourse(int courseId, const QString &nick)
{
    for (auto i = courses.begin(); i != courses.end(); ++i) {
        if (i->getId() == courseId) {
            if (!i->isStudentEnrolled(nick)) {
                i->enrollStudent(nick);
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}
