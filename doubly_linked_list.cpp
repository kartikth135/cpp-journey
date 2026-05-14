#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
        cout << val << " inserted\n";
    }

    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (head) { newNode->next = head; head->prev = newNode; }
        head = newNode;
        cout << val << " inserted at front\n";
    }

    // Delete by value
    void remove(int val) {
        Node* cur = head;
        while (cur && cur->data != val) cur = cur->next;
        if (!cur) { cout << val << " not found\n"; return; }
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        delete cur;
        cout << val << " deleted\n";
    }

    // Display forward
    void displayForward() {
        Node* cur = head;
        cout << "Forward: ";
        while (cur) { cout << cur->data << " <-> "; cur = cur->next; }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
        Node* cur = head;
        if (!cur) { cout << "List is empty\n"; return; }
        while (cur->next) cur = cur->next;
        cout << "Backward: ";
        while (cur) { cout << cur->data << " <-> "; cur = cur->prev; }
        cout << "NULL\n";
    }

    // Reverse the list
    void reverse() {
        Node* cur = head;
        Node* tmp = nullptr;
        while (cur) {
            tmp = cur->prev;
            cur->prev = cur->next;
            cur->next = tmp;
            cur = cur->prev;
        }
        if (tmp) head = tmp->prev;
        cout << "List reversed\n";
    }

    ~DoublyLinkedList() {
        while (head) { Node* tmp = head; head = head->next; delete tmp; }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertFront(5);

    list.displayForward();
    list.displayBackward();

    list.remove(20);
    list.displayForward();

    list.reverse();
    list.displayForward();

    return 0;
}