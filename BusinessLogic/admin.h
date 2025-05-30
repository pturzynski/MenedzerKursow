#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User
{
public:
    Admin(const string &username, const string &password);
    bool isAdmin() const override { return true; }
};

#endif // ADMIN_H
