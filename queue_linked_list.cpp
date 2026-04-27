#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Add element to rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) { front = rear = newNode; return; }
        rear->next = newNode;
        rear = newNode;
        cout << val << " enqueued\n";
    }

    // Remove element from front
    int dequeue() {
        if (!front) { cout << "Queue is empty\n"; return -1; }
        int val = front->data;
        Node* tmp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete tmp;
        return val;
    }

    // Peek at front
    int peek() {
        if (!front) { cout << "Queue is empty\n"; return -1; }
        return front->data;
    }

    bool isEmpty() { return front == nullptr; }

    void display() {
        if (!front) { cout << "Queue is empty\n"; return; }
        Node* cur = front;
        cout << "Queue (front to rear): ";
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << "\n";
    }

    ~Queue() {
        while (front) dequeue();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Front: " << q.peek() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();

    return 0;
}