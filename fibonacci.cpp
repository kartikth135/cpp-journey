#include <iostream>
#include <vector>
using namespace std;

// Recursive (slow for large n)
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative (fast)
long long fibIterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Memoization (fast + recursive)
vector<long long> memo(100, -1);
long long fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

int main() {
    cout << "=== Fibonacci Series ===\n\n";

    // Print first 10 terms
    cout << "First 10 terms: ";
    for (int i = 0; i < 10; i++)
        cout << fibIterative(i) << " ";
    cout << "\n\n";

    // Compare all three methods
    vector<int> tests = {5, 10, 20, 30};
    cout << "N\tRecursive\tIterative\tMemo\n";
    cout << "--\t---------\t---------\t----\n";
    for (int n : tests)
        cout << n << "\t" << fibRecursive(n) << "\t\t"
             << fibIterative(n) << "\t\t" << fibMemo(n) << "\n";

    return 0;
}