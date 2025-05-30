#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>
using namespace std;

class LoginFailedException : public runtime_error
{
public:
    LoginFailedException(const string& message);
};

class CourseEmptyException : public runtime_error
{
public:
    CourseEmptyException(const string& message);
};

#endif // EXCEPTIONS_H
