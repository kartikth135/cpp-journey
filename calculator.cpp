#include <iostream>
using namespace std;

double calculate(double a, char op, double b, bool& valid) {
    valid = true;
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) { cout << "Error: division by zero\n"; valid = false; return 0; }
            return a / b;
        case '%':
            if ((int)b == 0) { cout << "Error: modulo by zero\n"; valid = false; return 0; }
            return (int)a % (int)b;
        default:
            cout << "Error: unknown operator\n";
            valid = false;
            return 0;
    }
}

int main() {
    double a, b;
    char op;
    char again = 'y';

    cout << "=== Console Calculator ===\n";

    while (again == 'y' || again == 'Y') {
        cout << "Enter expression (e.g. 10 + 5): ";
        cin >> a >> op >> b;

        bool valid;
        double result = calculate(a, op, b, valid);

        if (valid)
            cout << a << " " << op << " " << b << " = " << result << "\n";

        cout << "Calculate again? (y/n): ";
        cin >> again;
    }

    cout << "Goodbye!\n";
    return 0;
}