#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() : top(-1) {}

    // Push element onto stack
    void push(int val) {
        if (top >= MAX - 1) { cout << "Stack overflow\n"; return; }
        arr[++top] = val;
        cout << val << " pushed\n";
    }

    // Pop element from stack
    int pop() {
        if (top < 0) { cout << "Stack underflow\n"; return -1; }
        return arr[top--];
    }

    // Peek at top element
    int peek() {
        if (top < 0) { cout << "Stack is empty\n"; return -1; }
        return arr[top];
    }

    bool isEmpty() { return top < 0; }

    // Display all elements
    void display() {
        if (top < 0) { cout << "Stack is empty\n"; return; }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();

    cout << "Top: " << s.peek() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    s.display();

    return 0;
}