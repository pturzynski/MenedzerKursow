#include "exceptions.h"

LoginFailedException::LoginFailedException(const string& message)
    : runtime_error(message) {}

CourseEmptyException::CourseEmptyException(const string& message)
    : runtime_error(message) {}
