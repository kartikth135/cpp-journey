#include <iostream>
#include <vector>
using namespace std;

// GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b;
}

// GCD of array
int gcdArray(vector<int>& arr) {
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++)
        result = gcd(result, arr[i]);
    return result;
}

// LCM of array
long long lcmArray(vector<int>& arr) {
    long long result = arr[0];
    for (int i = 1; i < arr.size(); i++)
        result = lcm(result, arr[i]);
    return result;
}

int main() {
    // Single pair
    cout << "=== GCD and LCM ===\n\n";
    vector<pair<int,int>> pairs = {{12, 18}, {100, 75}, {17, 13}, {48, 36}};

    cout << "Pair\t\tGCD\tLCM\n";
    cout << "----\t\t---\t---\n";
    for (auto& [a, b] : pairs)
        cout << a << ", " << b << "\t\t" << gcd(a, b) << "\t" << lcm(a, b) << "\n";

    // Array of numbers
    vector<int> arr = {12, 24, 36, 48};
    cout << "\nArray: ";
    for (int x : arr) cout << x << " ";
    cout << "\nGCD of array: " << gcdArray(arr) << "\n";
    cout << "LCM of array: " << lcmArray(arr) << "\n";

    return 0;
}