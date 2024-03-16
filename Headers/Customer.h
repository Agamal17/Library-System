#ifndef PROJECT_CUSTOMER_H
#define PROJECT_CUSTOMER_H

#include "User.h"
#include "Book.h"
#include "Library.h"
#include <string>
#include <iostream>
using namespace std;

class Customer: public User
{
private:
    Book borrowedBooks[5];
    int counter=0;
public:
    Customer(){}
    int getCounter(){return counter;}
    Customer(string);
    bool borrow(int, Library&);
    bool restore(int, Library&);
    int getBorrowedNum() const;
    Book* getBorrowed();
    void getInfo();
};
#endif //PROJECT_CUSTOMER_H
