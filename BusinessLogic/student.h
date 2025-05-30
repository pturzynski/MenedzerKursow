#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
class Student : public User
{
public:
    Student(const string &username, const string &password);
    bool isAdmin() const override { return false; }
};

#endif // STUDENT_H
