#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string getChoice(int c) {
    if (c == 0) return "Rock";
    if (c == 1) return "Paper";
    return "Scissors";
}

int getResult(int player, int cpu) {
    if (player == cpu) return 0;           // draw
    if ((player - cpu + 3) % 3 == 1) return 1; // win
    return -1;                              // lose
}

int main() {
    srand(time(0));

    int playerWins = 0, cpuWins = 0, draws = 0;
    char again = 'y';

    cout << "=== Rock Paper Scissors ===\n";
    cout << "0 = Rock | 1 = Paper | 2 = Scissors\n\n";

    while (again == 'y' || again == 'Y') {
        int playerChoice, cpuChoice;

        cout << "Your choice: ";
        cin >> playerChoice;

        if (playerChoice < 0 || playerChoice > 2) {
            cout << "Invalid choice\n"; continue;
        }

        cpuChoice = rand() % 3;

        cout << "You: " << getChoice(playerChoice)
             << " | CPU: " << getChoice(cpuChoice) << "\n";

        int result = getResult(playerChoice, cpuChoice);
        if (result == 1)  { cout << "You win!\n"; playerWins++; }
        else if (result == -1) { cout << "CPU wins!\n"; cpuWins++; }
        else { cout << "Draw!\n"; draws++; }

        cout << "Score -> You: " << playerWins
             << " | CPU: " << cpuWins
             << " | Draws: " << draws << "\n\n";

        cout << "Play again? (y/n): ";
        cin >> again;
    }

    cout << "\n=== Final Stats ===\n";
    cout << "Wins: " << playerWins << " | Losses: " << cpuWins << " | Draws: " << draws << "\n";
    int total = playerWins + cpuWins + draws;
    if (total > 0)
        cout << "Win rate: " << (playerWins * 100 / total) << "%\n";

    return 0;
}