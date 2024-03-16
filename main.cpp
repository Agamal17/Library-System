#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Book.h"
#include "Library.h"

template<class T>
int findbyID(int id,T *ids,int s)
{
    for (int i=0;i<s;i++)
    {
        if (id==ids[i].getID()) return i;
    }
    return -1;
}

int main() {
    Admin *admins = new Admin[User().maxadmins];
    int admincnt = 0;
    Customer *customers = new Customer[User().maxcustomers];
    int customercnt = 0;
    string name, user, pass;
    cout << "Enter Admin Credentials for Setup. \n Name:";
    getline(cin, name);
    cin.ignore();
    cout << "\nUsername: ";
    cin >> user;
    cout << "\nPassword";
    cin >> pass;
    admins[0] = Admin(name, user, pass);
    admincnt++;

    while (1) {
        cout << "\n#################\n Login with Admin Credentials:\n";
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;
        if (pass == admins[0].getPassword() && user == admins[0].getUsername())
            break;
        else cout << "Wrong Credentials";
    }
    cout << "Enter The maximum number of books in the library";
    int booknum;
    cin >> booknum;
    Library L(booknum);
    while (1) {
        int choice;
        cout << "\n\n################\n"
             << "1. Create new user\n"
             << "2. Display Users\n"
             << "3. Remove customer by ID\n"
             << "4. Add Book to Library\n"
             << "5. Remove Book from Library by ID\n"
             << "6. Borrow Book\n"
             << "7. Return Book\n"
             << "8. Display Books in Library\n"
             << "9. Display a book info by title\n"
             << "10. Display books of a certain category\n"
             << "11. Display books of certain author\n"
             << "12. Exit\n";
        cout << "Enter Choice Number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n1. Admin\n2. Customer";
                cin >> choice;
                if (choice == 1) {
                    cout << "Enter Admin Credentials\n Name:";
                    getline(cin, name);
                    cin.ignore();
                    cout << "\nUsername: ";
                    cin >> user;
                    cout << "\nPassword";
                    cin >> pass;
                    admins[admincnt] = Admin(name, user, pass);
                    admincnt++;
                } else {
                    cout << "Enter customer's name: ";
                    getline(cin, name);
                    cin.ignore();
                    customers[customercnt] = Customer(name);
                    customercnt++;
                }
                break;

            case 2:
                cout << "Admins: ";
                for (int i = 0; i < admincnt; i++)
                    admins[i].getInfo();
                cout << "\nCustomers: ";
                for (int i = 0; i < customercnt; i++)
                    customers[i].getInfo();
                break;

            case 3: {
                bool found = 0;
                cout << "Customers: \n";
                for (int i = 0; i < customercnt; i++)
                    customers[i].getInfo();
                int id;
                cout << "Enter Customer's ID that is to be removed: ";
                cin >> id;
                for (int i = 0; i < customercnt; i++) {
                    if (customers[i].getID() == id) {
                        for (int j = i + 1; j < customercnt; j++, i++) {
                            customers[i] = customers[j];
                        }
                        if (customercnt == User().maxcustomers) customers[User().maxcustomers - 1] = Customer();
                        customercnt--;
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    for (int i = 0; i < User().usercount; i++) {
                        if (User().IDs[i] == id) {
                            for (int j = i + 1; j < User().usercount; j++, i++) {
                                User().IDs[i] = User().IDs[j];
                            }
                            if (User().usercount == User().maxusers) User().IDs[User().maxusers - 1] = 0;
                            User().usercount--;
                        }
                    }
                } else cout << "ID Not found";
                break;
            }

            case 4: {
                string title, author, category;
                cout << "Enter Book Info: \nTitle: ";
                getline(cin, title);
                cin.ignore();
                cout << "\nAuthor: ";
                getline(cin, author);
                cin.ignore();
                cout << "\nCategory: ";
                getline(cin, category);
                cin.ignore();
                L.addBook(title, author, category);
                break;
            }

            case 5: {
                int id;
                cout << "Enter book ID: ";
                cin >> id;
                if (L.removeBook(id)) {
                    for (int i = 0; i < customercnt; i++) {
                        customers[i].restore(id, L);
                    }
                    cout << "Book removed" << endl;
                } else
                    cout << "Book not found" << endl;
                break;
            }
            case 6: {
                int cust_id, book_id, cust_index;
                cout << "Enter Customer ID: ";
                cin >> cust_id;
                cust_index = findbyID(cust_id, customers, customercnt);
                while (findbyID(cust_id, customers, customercnt) == -1) {
                    cout << "Customer ID not found." << endl;
                    cout << "Enter Customer ID: ";
                    cin >> cust_id;
                    cust_index = findbyID(cust_id, customers, customercnt);
                }
                if (customers[cust_id].getBorrowedNum() == 5) {
                    cout << "You are already borrowing 5 books";
                } else {
                    customers[cust_id].borrow(book_id, L);
                    cout << "Book borrowed!";
                }

                case 7: {
                    int cust_id, book_id, cust_index;
                    cout << "Enter Customer ID: ";
                    cin >> cust_id;
                    cust_index = findbyID(cust_id, customers, customercnt);
                    while (findbyID(cust_id, customers, customercnt) == -1) {
                        cout << "Customer ID not found." << endl;
                        cout << "Enter Customer ID: ";
                        cin >> cust_id;
                        cust_index = findbyID(cust_id, customers, customercnt);
                    }
                    cout << "Enter Book ID: ";
                    cin >> book_id;
                    while (findbyID(book_id, customers[cust_id].getBorrowed(), customers[cust_id].getBorrowedNum()) ==
                           1) {
                        cout << "Customer doesn't have the book." << endl;
                        cout << "Enter Book ID: ";
                        cin >> book_id;
                    }
                    customers[cust_id].restore(book_id, L);
                    cout << "Book restored!" << endl;
                    break;
                }

                case 8: {
                    cout << "Books: " << endl;
                    L.displayAll();
                    break;
                }
                case 9: {
                    string search;
                    cout << "Enter the title you're looking for: ";
                    cin >> search;
                    L.findTitle(search);
                    break;
                }
                case 10: {
                    string search;
                    cout << "Enter the category you're looking for: ";
                    cin >> search;
                    L.findCategory(search);
                    break;
                }
                case 11: {
                    string search;
                    cout << "Enter the author you're looking for: ";
                    cin >> search;
                    L.findAuthor(search);
                    break;
                }
                case 12:
                    exit(EXIT_SUCCESS);
                default: {
                    cout << "Invalid input." << endl;
                    break;
                }
            }

        }
    }
}