#include <iostream>
#include <string>
using namespace std;

// Encode message using Caesar cipher
string encode(string text, int shift) {
    shift = shift % 26;
    for (char& c : text) {
        if (isupper(c)) c = (c - 'A' + shift + 26) % 26 + 'A';
        else if (islower(c)) c = (c - 'a' + shift + 26) % 26 + 'a';
    }
    return text;
}

// Decode by reversing the shift
string decode(string text, int shift) {
    return encode(text, -shift);
}

int main() {
    string message;
    int shift;

    cout << "=== Caesar Cipher ===\n";
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter shift (1-25): ";
    cin >> shift;

    string encoded = encode(message, shift);
    string decoded = decode(encoded, shift);

    cout << "\nOriginal : " << message << "\n";
    cout << "Encoded  : " << encoded << "\n";
    cout << "Decoded  : " << decoded << "\n";

    return 0;
}