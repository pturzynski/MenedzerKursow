#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
protected:
    string username;
    string password;
public:
    User(const string &username, const string &password);
    string getNick() const;
    bool checkPassword(const string &password) const;
    virtual bool isAdmin() const = 0;
};

#endif // USER_H
