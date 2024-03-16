#include "Book.h"


Book::Book (string t, string a, string c): title(t),author(a),category(c){}
Book::Book ()
{
    bool flag=1;
    while(flag) {
        flag=0;
        srand(time(0));
        id = 6000 + (rand() % 16000);

        for (int i: ids) {
            if (i == id) {
                flag=1;
                break;
            }
        }
    }
}
int Book:: getID()
{
    return id;
}
string Book::gettitle()
{
    return title;
}
string Book::getauthor()
{
    return author;
}
string Book::getcategory()
{
    return category;
}
bool Book::getborrowed()
{
    return borrowed;
}
void Book::print()
{
    cout<<"Book info: \n";
    cout<<"Book id :: "<<id<<endl;
    cout<<"Book title :: "<<title<<endl;
    cout<<"Book author :: "<<author<<endl;
    cout<<"Book category :: "<<category<<endl;
    if (borrowed)
        cout<<"Borrowed :: Yes"<<endl;
    else
        cout<<"Borrowed :: No"<<endl;
}