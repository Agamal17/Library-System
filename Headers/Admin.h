#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#include <string>
#include <iostream>
using namespace std;
#include "User.h"

class Admin: public User
{
    private:
        string username;
        string password;
    public:
        Admin(){}
        Admin(string&, string&, string&);
        string getUsername();
        string getPassword();
        void changeCredentials(string&, string&);
};
#endif //PROJECT_ADMIN_H
