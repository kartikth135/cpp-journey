#include <iostream>
#include <vector>
using namespace std;

vector<char> board(9, ' ');

void display() {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << (board[i] == ' ' ? (char)('1' + i) : board[i]) << " ";
        if (i % 3 != 2) cout << "|";
        else if (i != 8) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

bool checkWin(char c) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (auto& w : wins)
        if (board[w[0]] == c && board[w[1]] == c && board[w[2]] == c) return true;
    return false;
}

bool isFull() {
    for (char c : board) if (c == ' ') return false;
    return true;
}

int main() {
    char players[2] = {'X', 'O'};
    int turn = 0;

    cout << "=== Tic Tac Toe ===\n";
    cout << "Players: X and O | Enter cell number (1-9)\n";

    while (true) {
        display();
        int move;
        cout << "Player " << players[turn] << " enter move: ";
        cin >> move;
        move--;

        if (move < 0 || move > 8 || board[move] != ' ') {
            cout << "Invalid move, try again\n";
            continue;
        }

        board[move] = players[turn];

        if (checkWin(players[turn])) {
            display();
            cout << "Player " << players[turn] << " wins!\n";
            break;
        }

        if (isFull()) {
            display();
            cout << "It's a draw!\n";
            break;
        }

        turn = 1 - turn;
    }

    return 0;
}