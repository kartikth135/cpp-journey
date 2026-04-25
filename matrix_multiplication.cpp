#include <iostream>
using namespace std;

const int MAX = 10;

void multiply(int a[][MAX], int b[][MAX], int res[][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void display(int mat[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";
        cout << "\n";
    }
}

int main() {
    int a[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int b[MAX][MAX] = {{7, 8}, {9, 10}, {11, 12}};
    int res[MAX][MAX];

    int r1 = 2, c1 = 3, c2 = 2;

    cout << "Matrix A (2x3):\n"; display(a, r1, c1);
    cout << "\nMatrix B (3x2):\n"; display(b, c1, c2);

    multiply(a, b, res, r1, c1, c2);

    cout << "\nResult (2x2):\n"; display(res, r1, c2);

    return 0;
}