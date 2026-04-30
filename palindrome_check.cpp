#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Check if string is palindrome
bool isStringPalindrome(string s) {
    // Remove spaces and convert to lowercase
    string cleaned = "";
    for (char c : s)
        if (isalnum(c)) cleaned += tolower(c);

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

// Check if number is palindrome
bool isNumberPalindrome(int n) {
    if (n < 0) return false;
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    // String palindrome tests
    vector<string> words = {"racecar", "hello", "A man a plan a canal Panama", "level", "world"};
    cout << "=== String Palindrome ===\n";
    for (string& w : words)
        cout << "\"" << w << "\" -> " << (isStringPalindrome(w) ? "Yes" : "No") << "\n";

    // Number palindrome tests
    vector<int> nums = {121, 123, 1221, 12321, 100};
    cout << "\n=== Number Palindrome ===\n";
    for (int n : nums)
        cout << n << " -> " << (isNumberPalindrome(n) ? "Yes" : "No") << "\n";

    return 0;
}