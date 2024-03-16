#include "../Headers/Library.h"

Library::Library(int num){
    books = new Book[num];
}
void Library::reSize(int num, int count){
    Book *tmp_books = new Book[num];
    for(int i=0;i<count;i++)
        tmp_books[i] = books[i];
    delete[] books;
    books = tmp_books;
}
void Library::addBook(string title, string author, string category) {
    num_of_books++;
    books[num_of_books] = Book(title, author, category);
}
bool Library::removeBook(int ID) {
    for (int i=0;i<num_of_books;i++){
        if (books[i].id==ID){
            books[i].~Book();
            books[i]=books[num_of_books-1];
            num_of_books--;
            return true;
        }
    }
    return false;
}

void Library::displayAll() {
    for(int i=0;i<num_of_books;i++){
        books[i].print();
    }
}

void Library::displayBorrowed() {
    for(int i=0;i<num_of_books;i++){
        if (books[i].borrowed)
            books[i].print();
    }
}
void Library::display(Book* b, int count) {
    for(int i=0;i<count;i++){
        if (b[i].borrowed)
            b[i].print();
    }
}

void Library::displayNonBorrowed() {
    for(int i=0;i<num_of_books;i++){
        if (!(books[i].borrowed))
            books[i].print();
    }
}
void Library::findTitle(string name) {
    for(int i=0;i<num_of_books;i++){
        size_t found = books[i].title.find(name);
        if (found != string::npos)
            books[i].print();
    }
}
void Library::findAuthor(string name) {
    for(int i=0;i<num_of_books;i++){
        size_t found = books[i].author.find(name);
        if (found != string::npos)
            books[i].print();
    }
}
void Library::findCategory(string cat) {
    for(int i=0;i<num_of_books;i++){
        if (books[i].category==cat)
            books[i].print();
    }
}

int Library::getNumBook(){
    return num_of_books;
}

