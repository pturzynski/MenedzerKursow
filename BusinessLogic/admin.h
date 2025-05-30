#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User
{
public:
    Admin(const string &username, const string &password);
};

#endif // ADMIN_H
