#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push element onto stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed\n";
    }

    // Pop element from stack
    int pop() {
        if (!top) { cout << "Stack is empty\n"; return -1; }
        int val = top->data;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        return val;
    }

    // Peek at top element
    int peek() {
        if (!top) { cout << "Stack is empty\n"; return -1; }
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    // Display all elements
    void display() {
        if (!top) { cout << "Stack is empty\n"; return; }
        Node* cur = top;
        cout << "Stack (top to bottom): ";
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << "\n";
    }

    ~Stack() {
        while (top) pop();
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