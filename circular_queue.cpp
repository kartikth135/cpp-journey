#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) : capacity(cap), front(-1), rear(-1), size(0) {
        arr = new int[capacity];
    }

    bool isFull()  { return size == capacity; }
    bool isEmpty() { return size == 0; }

    // Add element to rear
    void enqueue(int val) {
        if (isFull()) { cout << "Queue is full\n"; return; }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        if (front == -1) front = 0;
        size++;
        cout << val << " enqueued\n";
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) { front = rear = -1; }
        return val;
    }

    // Peek at front
    int peek() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return arr[front];
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (int i = 0; i < size; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << "\n";
    }

    ~CircularQueue() { delete[] arr; }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // full
    q.display();

    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    cout << "Front: " << q.peek() << "\n";

    return 0;
}