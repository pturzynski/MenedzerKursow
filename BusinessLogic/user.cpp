#include "user.h"

User::User(const string &username, const string &password)
    : username(username), password(password) {}


string User::getNick() const {
    return username;
}

bool User::checkPassword(const string &p) const {
    return p == password;
}
