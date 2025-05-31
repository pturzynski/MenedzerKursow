#include "coursemanager.h"

CourseManager::CourseManager() {
    courses.emplace_back(nextId++, "Matematyka", "Podstawy matematyki");
    courses.emplace_back(nextId++, "Fizyka", "Podstawy fizyki");
    courses.emplace_back(nextId++, "Programowanie C++", "Nauka programowania w C++");

}

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

const QList<Course> CourseManager::getCourses() const {
    return courses;
}
