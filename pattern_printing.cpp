#include <iostream>
using namespace std;

// Right triangle
void rightTriangle(int n) {
    cout << "Right Triangle:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << "\n";
    }
}

// Inverted triangle
void invertedTriangle(int n) {
    cout << "\nInverted Triangle:\n";
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << "\n";
    }
}

// Pyramid
void pyramid(int n) {
    cout << "\nPyramid:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
}

// Diamond
void diamond(int n) {
    cout << "\nDiamond:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
}

// Number pattern
void numberPattern(int n) {
    cout << "\nNumber Pattern:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    int n = 5;
    rightTriangle(n);
    invertedTriangle(n);
    pyramid(n);
    diamond(n);
    numberPattern(n);

    return 0;
}