#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book
{
private :
    int id;
    string title;
    string author;
    string category;
    bool borrowed;
public:
    inline static int ids[100];
    friend class Library;
    friend class Customer;
    Book ();
    Book (string t, string a, string c);
    int getID();
    string gettitle();
    string getauthor();
    string getcategory();
    bool getborrowed();
    void print();
};
#endif //PROJECT_BOOK_H