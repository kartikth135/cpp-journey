#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess, attempts = 0;
    char playAgain = 'y';

    cout << "=== Number Guessing Game ===\n";
    cout << "Guess a number between 1 and 100\n\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        attempts = 0;
        secret = rand() % 100 + 1;

        while (true) {
            cout << "Your guess: ";
            cin >> guess;
            attempts++;

            if (guess < 1 || guess > 100) {
                cout << "Please enter a number between 1 and 100\n";
                attempts--;
            } else if (guess < secret) {
                cout << "Too low! Try higher\n";
            } else if (guess > secret) {
                cout << "Too high! Try lower\n";
            } else {
                cout << "Correct! You got it in " << attempts << " attempt";
                if (attempts > 1) cout << "s";
                cout << "\n";

                if (attempts <= 5) cout << "Excellent!\n";
                else if (attempts <= 10) cout << "Good job!\n";
                else cout << "Keep practicing!\n";
                break;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}