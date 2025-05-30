#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
class Student : public User
{
public:
    Student(const string &username, const string &password);
};

#endif // STUDENT_H
