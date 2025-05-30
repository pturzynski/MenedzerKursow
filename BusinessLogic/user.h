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
};

#endif // USER_H
