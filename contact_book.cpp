#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

void addContact(vector<Contact>& contacts) {
    Contact c;
    cout << "Name: "; cin.ignore(); getline(cin, c.name);
    cout << "Phone: "; getline(cin, c.phone);
    cout << "Email: "; getline(cin, c.email);
    contacts.push_back(c);
    cout << "Contact added!\n";
}

void searchContact(vector<Contact>& contacts) {
    string query;
    cout << "Search by name: "; cin.ignore(); getline(cin, query);
    bool found = false;
    for (Contact& c : contacts) {
        if (c.name.find(query) != string::npos) {
            cout << "\nName:  " << c.name << "\n";
            cout << "Phone: " << c.phone << "\n";
            cout << "Email: " << c.email << "\n";
            found = true;
        }
    }
    if (!found) cout << "No contact found\n";
}

void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Delete contact name: "; cin.ignore(); getline(cin, name);
    auto it = remove_if(contacts.begin(), contacts.end(), [&](Contact& c) {
        return c.name == name;
    });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted\n";
    } else cout << "Contact not found\n";
}

void listAll(vector<Contact>& contacts) {
    if (contacts.empty()) { cout << "No contacts\n"; return; }
    cout << "\n--- All Contacts ---\n";
    for (int i = 0; i < contacts.size(); i++)
        cout << i + 1 << ". " << contacts[i].name << " | " << contacts[i].phone << "\n";
}

int main() {
    vector<Contact> contacts;
    int choice;

    cout << "=== Contact Book ===\n";
    while (true) {
        cout << "\n1. Add  2. Search  3. Delete  4. List  5. Exit\n";
        cout << "Choice: "; cin >> choice;
        if (choice == 1) addContact(contacts);
        else if (choice == 2) searchContact(contacts);
        else if (choice == 3) deleteContact(contacts);
        else if (choice == 4) listAll(contacts);
        else { cout << "Goodbye!\n"; break; }
    }
    return 0;
}