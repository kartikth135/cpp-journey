#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search
int binarySearchIterative(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Recursive binary search
int binarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
    else return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 67, 99};

    int target = 23;

    int idx1 = binarySearchIterative(arr, target);
    cout << "Iterative: " << target << " found at index " << idx1 << "\n";

    int idx2 = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    cout << "Recursive: " << target << " found at index " << idx2 << "\n";

    int missing = 50;
    int idx3 = binarySearchIterative(arr, missing);
    cout << "Search for " << missing << ": " << (idx3 == -1 ? "not found" : "found") << "\n";

    return 0;
}