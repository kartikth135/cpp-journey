#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
    string issuedTo;
};

class Library {
    vector<Book> books;
    int nextId = 1;

public:
    void addBook(string title, string author) {
        books.push_back({nextId++, title, author, false, ""});
        cout << "Book added: " << title << " (ID: " << nextId - 1 << ")\n";
    }

    void issueBook(int id, string member) {
        for (Book& b : books) {
            if (b.id == id) {
                if (b.issued) { cout << "Book already issued to " << b.issuedTo << "\n"; return; }
                b.issued = true;
                b.issuedTo = member;
                cout << "\"" << b.title << "\" issued to " << member << "\n";
                return;
            }
        }
        cout << "Book ID " << id << " not found\n";
    }

    void returnBook(int id) {
        for (Book& b : books) {
            if (b.id == id) {
                if (!b.issued) { cout << "Book was not issued\n"; return; }
                cout << "\"" << b.title << "\" returned by " << b.issuedTo << "\n";
                b.issued = false;
                b.issuedTo = "";
                return;
            }
        }
        cout << "Book ID " << id << " not found\n";
    }

    void searchBook(string query) {
        bool found = false;
        cout << "\nSearch results for \"" << query << "\":\n";
        for (Book& b : books) {
            if (b.title.find(query) != string::npos ||
                b.author.find(query) != string::npos) {
                cout << "  ID:" << b.id << " | " << b.title
                     << " by " << b.author
                     << " | " << (b.issued ? "Issued to " + b.issuedTo : "Available") << "\n";
                found = true;
            }
        }
        if (!found) cout << "  No results found\n";
    }

    void listAll() {
        if (books.empty()) { cout << "No books in library\n"; return; }
        cout << "\n--- Library Catalog ---\n";
        for (Book& b : books)
            cout << "ID:" << b.id << " | " << b.title
                 << " by " << b.author
                 << " | " << (b.issued ? "Issued to " + b.issuedTo : "Available") << "\n";
    }

    void availableBooks() {
        cout << "\n--- Available Books ---\n";
        bool any = false;
        for (Book& b : books) {
            if (!b.issued) {
                cout << "ID:" << b.id << " | " << b.title << " by " << b.author << "\n";
                any = true;
            }
        }
        if (!any) cout << "No books available\n";
    }
};

int main() {
    Library lib;

    lib.addBook("The C++ Programming Language", "Bjarne Stroustrup");
    lib.addBook("Clean Code", "Robert Martin");
    lib.addBook("Data Structures", "Mark Allen Weiss");
    lib.addBook("Introduction to Algorithms", "Cormen");

    lib.listAll();

    cout << "\n";
    lib.issueBook(1, "Alice");
    lib.issueBook(3, "Bob");
    lib.issueBook(1, "Charlie");

    lib.availableBooks();

    cout << "\n";
    lib.returnBook(1);
    lib.availableBooks();

    lib.searchBook("Code");

    return 0;
}