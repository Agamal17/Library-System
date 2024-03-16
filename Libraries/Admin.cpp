#include "../Headers/Admin.h"

Admin::Admin(string &name, string& username, string& password) {
    setName(name);
    this->username=username;
    this->password=password;
}

string Admin::getUsername() {
    return username;
}

string Admin::getPassword() {
    return password;
}

void Admin::changeCredentials(string& username, string& password) {
    this->username=username;
    this->password=password;
}