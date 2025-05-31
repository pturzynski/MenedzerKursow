#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
#include "course.h"
#include "user.h"
#include <QList>
#include <QString>
#include "BusinessLogic_global.h"

class BUSINESSLOGIC_EXPORT CourseManager
{
private:
    QList<Course> courses;
    int nextId = 1;

public:
    CourseManager();

    void addCourse(const User *user, const QString &name, const QString &description); //dla admina
    bool enrollToCourse(int courseId, const QString &nick); //dla studenta
    const QList<Course> getCourses() const;
};

#endif // COURSEMANAGER_H
