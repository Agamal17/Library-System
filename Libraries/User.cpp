#include "../Headers/User.h"

int User::getID() const {
    return ID;
}

string User::getName() {
    return name;
}

void User::setID(int& ID) {
    this->ID = ID;
}

void User::setName(string& name) {
    this->name = name;
    bool flag=1;
    while(flag) {
        flag=0;
        srand(time(0));
        ID = 1000 + (rand() % 4000);

        for (int i=0;i<usercount;i++) {
            if (IDs[i] == ID) {
                flag=1;
                break;
            }
        }
    }
    IDs[usercount] = ID;
    usercount++;
}

void User::getInfo() {
    cout<<"User's name is: "<<name
    <<"\n User's ID is: "<<ID<<endl;
}