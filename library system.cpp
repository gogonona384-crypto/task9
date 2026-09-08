#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title, author;
    bool isBorrowed;
    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}
};

int main() {
    vector<Book> catalog;
    int opt;
    cout << "=== Library Management System ===\n";
    while(true) {
        cout << "\n1. Add Book\n2. Borrow Book\n3. Return Book\n4. Display All\n5. Exit\nChoose: ";
        cin >> opt; cin.ignore();
        if(opt == 1) {
            string t, a; cout << "Enter title: "; getline(cin, t);
            cout << "Enter author: "; getline(cin, a);
            catalog.push_back(Book(t, a));
            cout << "Book \"" << t << "\" added.\n";
        } else if(opt == 2) {
            string t; cout << "Enter title to borrow: "; getline(cin, t);
            for(auto &b : catalog) {
                if(b.title == t && !b.isBorrowed) {
                    b.isBorrowed = true;
                    cout << "\"" << t << "\" borrowed successfully.\n";
                }
            }
        } else if(opt == 3) {
            string t; cout << "Enter title to return: "; getline(cin, t);
            for(auto &b : catalog) {
                if(b.title == t && b.isBorrowed) {
                    b.isBorrowed = false;
                    cout << "\"" << t << "\" returned successfully.\n";
                }
            }
        } else if(opt == 4) {
            for(auto &b : catalog) {
                cout << "Title: " << b.title << " | Author: " << b.author 
                     << " | Status: " << (b.isBorrowed ? "Borrowed" : "Available") << "\n";
            }
        } else if(opt == 5) {
            cout << "Goodbye!\n"; break;
        }
    }
    return 0;
}
