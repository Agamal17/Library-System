#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <string>
#include <iostream>
using namespace std;

class User
{
    protected:
        int ID;
        string name;
    public:
        inline static const int maxcustomers=100,maxadmins=5,maxusers= maxcustomers + maxadmins;
        inline static int IDs[maxusers]; // for validating that ID isn't repeated
        inline static int usercount=0;

        User(){}
        int getID() const;
        string getName();
        void setID(int&);
        void setName(string&);
        void getInfo();
};
#endif //PROJECT_USER_H
