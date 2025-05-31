#ifndef USER_H
#define USER_H
#include <QString>
using namespace std;

class User
{
protected:
    QString username;
    QString password;
public:
    User(const QString &username, const QString &password);
    QString getNick() const;
    bool checkPassword(const QString &password) const;
    virtual bool isAdmin() const = 0;
    virtual ~User() = default;
};

#endif // USER_H
