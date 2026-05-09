#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition array around pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Random pivot to avoid worst case
int randomPartition(vector<int>& arr, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[randIdx], arr[high]);
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = randomPartition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

void display(vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 45, 67, 3};

    cout << "Before: "; display(arr);
    quickSort(arr, 0, arr.size() - 1);
    cout << "After:  "; display(arr);

    // Already sorted case
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7};
    cout << "\nAlready sorted: "; display(sorted);
    quickSort(sorted, 0, sorted.size() - 1);
    cout << "After sort:     "; display(sorted);

    // Reverse sorted case
    vector<int> rev = {9, 8, 7, 6, 5, 4, 3};
    cout << "\nReverse sorted: "; display(rev);
    quickSort(rev, 0, rev.size() - 1);
    cout << "After sort:     "; display(rev);

    return 0;
}