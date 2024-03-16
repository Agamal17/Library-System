#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include "Book.h"
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;


class Library {
private:
    Book* books;
    int num_of_books=0;
public:
    Library(int);
    friend class Customer;
    void reSize(int, int);
    void addBook(string , string , string);
    bool removeBook(int);
    void displayAll();
    void display(Book *, int);
    void displayBorrowed();
    void displayNonBorrowed();
    void findAuthor(string);
    void findCategory(string);
    void findTitle(string);
    int getNumBook();
};
#endif //PROJECT_LIBRARY_H
