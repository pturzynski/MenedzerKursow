#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include "BusinessLogic_global.h"
#include <stdexcept>
#include <string>
using namespace std;

class BUSINESSLOGIC_EXPORT LoginFailedException : public runtime_error
{
public:
    LoginFailedException(const string& message);
};

class BUSINESSLOGIC_EXPORT CourseEmptyException : public runtime_error
{
public:
    CourseEmptyException(const string& message);
};

#endif // EXCEPTIONS_H
