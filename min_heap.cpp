#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    // Get parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element up to maintain heap property
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Move element down to maintain heap property
    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Insert element
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        cout << val << " inserted\n";
    }

    // Extract minimum element
    int extractMin() {
        if (heap.empty()) { cout << "Heap is empty\n"; return -1; }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return minVal;
    }

    // Peek at minimum
    int getMin() {
        if (heap.empty()) { cout << "Heap is empty\n"; return -1; }
        return heap[0];
    }

    void display() {
        cout << "Heap: ";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }

    bool isEmpty() { return heap.empty(); }
};

int main() {
    MinHeap h;

    vector<int> vals = {35, 10, 50, 5, 20, 15, 30};
    for (int v : vals) h.insert(v);

    cout << "\n"; h.display();
    cout << "Min: " << h.getMin() << "\n\n";

    cout << "Extracting in order:\n";
    while (!h.isEmpty())
        cout << h.extractMin() << " ";
    cout << "\n";

    return 0;
}