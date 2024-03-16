#include "../Headers/Customer.h"


Customer::Customer(string name) {
    setName(name);
}

bool Customer::borrow(int ID, Library& l){
    if (counter<5){
        for (int i=0;i<l.num_of_books;i++){
            if ( l.books[i].id == ID && (!l.books[i].borrowed) ){
                l.books[i].borrowed=1;
                borrowedBooks[counter] = l.books[i];
                counter++;
                return true;
            }
        }
        cout<<"Book not found or already borrowed";
        return false;
    }
    else{
        cout<<"Maximum number of books borrowed is reached.";
        return false;
    }
}

bool Customer::restore(int ID, Library& l) {
    for (int i=0;i<getBorrowedNum();i++)
    {
        if (borrowedBooks[i].id==ID)
        {
            borrowedBooks[i].borrowed=0;
            for (int j=i+1;j<getBorrowedNum();j++,i++){
                borrowedBooks[i]=borrowedBooks[j];
            }
            if (counter==5) borrowedBooks[4]=Book();
            counter--;
            for (int i=0;i<l.num_of_books;i++){
                if (l.books[i].id==ID){
                    l.books[i].borrowed=0;
                    return true;
                }
            }
        }
    }
    cout<<"Book not found"; return false;
}

int Customer::getBorrowedNum() const {
    return counter;
}

Book* Customer::getBorrowed(){
    return borrowedBooks;
}

void Customer::getInfo(){
    User::getInfo();
    cout<<endl<<"Borrowed Books are: ";
    for (int i=0;i<counter;i++){
        cout<<borrowedBooks[i].title<<endl;
    }
}