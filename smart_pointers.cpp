#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Animal {
    string name;
public:
    Animal(string n) : name(n) { cout << name << " created\n"; }
    ~Animal() { cout << name << " destroyed\n"; }
    void speak() { cout << name << " says hello!\n"; }
};

void uniquePtrDemo() {
    cout << "=== unique_ptr Demo ===\n";

    // Only one owner at a time
    unique_ptr<Animal> ptr1 = make_unique<Animal>("Dog");
    ptr1->speak();

    // Transfer ownership
    unique_ptr<Animal> ptr2 = move(ptr1);
    ptr2->speak();

    if (!ptr1) cout << "ptr1 is now empty after move\n";
    // ptr2 goes out of scope here, Dog is destroyed
}

void sharedPtrDemo() {
    cout << "\n=== shared_ptr Demo ===\n";

    // Multiple owners allowed
    shared_ptr<Animal> ptr1 = make_shared<Animal>("Cat");
    cout << "Ref count: " << ptr1.use_count() << "\n";

    {
        shared_ptr<Animal> ptr2 = ptr1; // shared ownership
        cout << "Ref count: " << ptr1.use_count() << "\n";
        ptr2->speak();
    } // ptr2 goes out of scope, count drops

    cout << "Ref count after ptr2 out of scope: " << ptr1.use_count() << "\n";
    // Cat destroyed when ptr1 goes out of scope
}

int main() {
    uniquePtrDemo();
    sharedPtrDemo();
    cout << "\nAll done!\n";
    return 0;
}