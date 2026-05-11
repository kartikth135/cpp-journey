#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Write lines to file
void writeFile(string filename, vector<string>& lines) {
    ofstream file(filename);
    if (!file) { cout << "Cannot open file\n"; return; }
    for (string& line : lines) file << line << "\n";
    file.close();
    cout << "Written to " << filename << "\n";
}

// Read and display file
void readFile(string filename) {
    ifstream file(filename);
    if (!file) { cout << "File not found\n"; return; }
    string line;
    int lineNo = 1;
    cout << "\n--- " << filename << " ---\n";
    while (getline(file, line))
        cout << lineNo++ << ": " << line << "\n";
    file.close();
}

// Append line to file
void appendFile(string filename, string line) {
    ofstream file(filename, ios::app);
    if (!file) { cout << "Cannot open file\n"; return; }
    file << line << "\n";
    file.close();
    cout << "Appended: " << line << "\n";
}

// Search for word in file
void searchFile(string filename, string word) {
    ifstream file(filename);
    if (!file) { cout << "File not found\n"; return; }
    string line;
    int lineNo = 1, count = 0;
    cout << "\nSearching for \"" << word << "\":\n";
    while (getline(file, line)) {
        if (line.find(word) != string::npos) {
            cout << "Line " << lineNo << ": " << line << "\n";
            count++;
        }
        lineNo++;
    }
    file.close();
    cout << "Found " << count << " match(es)\n";
}

// Count lines words and characters
void fileStats(string filename) {
    ifstream file(filename);
    if (!file) { cout << "File not found\n"; return; }
    int lines = 0, words = 0, chars = 0;
    string line;
    while (getline(file, line)) {
        lines++;
        chars += line.size();
        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) inWord = false;
            else if (!inWord) { inWord = true; words++; }
        }
    }
    file.close();
    cout << "\nStats: Lines=" << lines << " Words=" << words << " Chars=" << chars << "\n";
}

int main() {
    string filename = "sample.txt";

    vector<string> lines = {
        "Hello World",
        "C++ file operations",
        "Reading and writing files",
        "Search and append demo"
    };

    writeFile(filename, lines);
    readFile(filename);
    appendFile(filename, "New appended line");
    readFile(filename);
    searchFile(filename, "file");
    fileStats(filename);

    return 0;
}