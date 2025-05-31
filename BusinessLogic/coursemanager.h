#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
#include "course.h"
#include "user.h"
#include <QList>
#include <QString>

class CourseManager
{
private:
    QList<Course> courses;
    int nextId = 1;

public:
    CourseManager();

    void addCourse(const User *user, const QString &name, const QString &description); //dla admina
    bool enrollToCourse(int courseId, const QString &nick); //dla studenta
};

#endif // COURSEMANAGER_H
