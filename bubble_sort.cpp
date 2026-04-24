#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swap happened, array is already sorted
        if (!swapped) break;
    }
}

void display(vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Before: "; display(arr);
    bubbleSort(arr);
    cout << "After:  "; display(arr);

    // Already sorted case
    vector<int> sorted = {1, 2, 3, 4, 5};
    cout << "\nAlready sorted: "; display(sorted);
    bubbleSort(sorted);
    cout << "After sort:     "; display(sorted);

    return 0;
}