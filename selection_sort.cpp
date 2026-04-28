#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find minimum element in unsorted part
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;

        // Swap minimum with first unsorted element
        if (minIdx != i) swap(arr[i], arr[minIdx]);

        // Show progress
        cout << "Step " << i + 1 << ": ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45};

    cout << "Before: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    selectionSort(arr);

    cout << "\nAfter:  ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}