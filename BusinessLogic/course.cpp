#include "course.h"
#include "exceptions.h"

Course::Course(int id, const string &name, const string &description)
    : id(id), name(name), description(description)
{
    if (name.empty() || description.empty()) {
        throw CourseEmptyException("Nazwa i opis nie mogą być puste");
    }
}

int Course::getId() const
{
    return id;
}

string Course::getName() const
{
    return name;
}

string Course::getDescription() const
{
    return description;
}

void Course::enrollStudent(const string &nick)
{
    if(nick.empty()){
        throw invalid_argument("Nick nie może być pusty");
    }
    if(!isStudentEnrolled(nick)){
        enrolledStudents.push_back(nick);
    }
}

const vector<string> Course::getEnrolledStudents() const
{
    return enrolledStudents;
}

bool Course::isStudentEnrolled(const string &nick) const
{
    for(auto i = enrolledStudents.cbegin(); i != enrolledStudents.cend(); i++){
        if(*i == nick){
            return true;
        }
    }
    return false;
}
