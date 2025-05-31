#include "course.h"
#include "exceptions.h"

Course::Course(int id, const QString &name, const QString &description)
    : id(id), name(name), description(description)
{
    if (name.isEmpty() || description.isEmpty()) {
        throw CourseEmptyException("Nazwa i opis nie mogą być puste");
    }
}

int Course::getId() const
{
    return id;
}

QString Course::getName() const
{
    return name;
}

QString Course::getDescription() const
{
    return description;
}

void Course::enrollStudent(const QString &nick)
{
    if(nick.isEmpty()){
        throw invalid_argument("Nick nie może być pusty");
    }
    if(!isStudentEnrolled(nick)){
        enrolledStudents.push_back(nick);
    }
}

const QList<QString> Course::getEnrolledStudents() const
{
    return enrolledStudents;
}

bool Course::isStudentEnrolled(const QString &nick) const
{
    for(auto i = enrolledStudents.cbegin(); i != enrolledStudents.cend(); i++){
        if(*i == nick){
            return true;
        }
    }
    return false;
}
