#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // Don't take item i
            dp[i][w] = dp[i - 1][w];
            // Take item i if it fits
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
        }
    }

    // Trace back selected items
    cout << "Selected items:\n";
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "  Item " << i << " (weight=" << weights[i-1] << ", value=" << values[i-1] << ")\n";
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5, 1};
    vector<int> values  = {3, 4, 5, 6, 2};
    int capacity = 8;

    cout << "=== 0/1 Knapsack ===\n\n";
    cout << "Items:\n";
    for (int i = 0; i < weights.size(); i++)
        cout << "  Item " << i+1 << ": weight=" << weights[i] << " value=" << values[i] << "\n";
    cout << "Capacity: " << capacity << "\n\n";

    int maxVal = knapsack(weights, values, capacity);
    cout << "\nMax value: " << maxVal << "\n";

    return 0;
}