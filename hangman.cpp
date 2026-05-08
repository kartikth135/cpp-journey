#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawHangman(int lives) {
    cout << "\n";
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  |   " << (lives < 6 ? "O" : " ") << "\n";
    cout << "  |  " << (lives < 4 ? "/" : " ") << (lives < 5 ? "|" : " ") << (lives < 3 ? "\\" : " ") << "\n";
    cout << "  |  " << (lives < 2 ? "/" : " ") << " " << (lives < 1 ? "\\" : " ") << "\n";
    cout << "  |\n";
    cout << "=====\n\n";
}

int main() {
    srand(time(0));

    vector<string> words = {"programming", "computer", "algorithm", "variable",
                            "function", "pointer", "template", "inheritance"};

    char again = 'y';

    while (again == 'y' || again == 'Y') {
        string word = words[rand() % words.size()];
        string guessed(word.size(), '_');
        vector<char> tried;
        int lives = 6;

        cout << "=== Hangman ===\n";

        while (lives > 0 && guessed != word) {
            drawHangman(lives);

            cout << "Word: ";
            for (char c : guessed) cout << c << " ";
            cout << "\n";

            cout << "Tried: ";
            for (char c : tried) cout << c << " ";
            cout << "\n";

            cout << "Lives: " << lives << "\n";
            cout << "Guess a letter: ";
            char ch; cin >> ch;
            ch = tolower(ch);

            // Already tried
            if (find(tried.begin(), tried.end(), ch) != tried.end()) {
                cout << "Already tried that letter!\n";
                continue;
            }

            tried.push_back(ch);

            // Check if letter is in word
            bool found = false;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == ch) {
                    guessed[i] = ch;
                    found = true;
                }
            }

            if (!found) { cout << "Wrong!\n"; lives--; }
            else cout << "Correct!\n";
        }

        drawHangman(lives);

        if (guessed == word) cout << "You won! Word was: " << word << "\n";
        else cout << "Game over! Word was: " << word << "\n";

        cout << "\nPlay again? (y/n): ";
        cin >> again;
    }

    return 0;
}