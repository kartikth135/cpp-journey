#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }

    // Delete by value
    void remove(int val) {
        if (!head) return;
        if (head->data == val) { Node* tmp = head; head = head->next; delete tmp; return; }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (cur->next) { Node* tmp = cur->next; cur->next = tmp->next; delete tmp; }
    }

    // Display all nodes
    void display() {
        Node* cur = head;
        while (cur) { cout << cur->data << " -> "; cur = cur->next; }
        cout << "NULL\n";
    }

    ~LinkedList() {
        while (head) { Node* tmp = head; head = head->next; delete tmp; }
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    cout << "List: "; list.display();

    list.remove(20);
    cout << "After deleting 20: "; list.display();

    list.remove(10);
    cout << "After deleting 10: "; list.display();

    return 0;
}