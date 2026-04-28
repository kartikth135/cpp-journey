#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string owner;
    double balance;
    int accountNo;

public:
    BankAccount(string name, int accNo, double initial = 0)
        : owner(name), accountNo(accNo), balance(initial) {}

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) { cout << "Invalid deposit amount\n"; return; }
        balance += amount;
        cout << "Deposited $" << amount << " | New balance: $" << balance << "\n";
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) { cout << "Invalid withdraw amount\n"; return; }
        if (amount > balance) { cout << "Insufficient funds\n"; return; }
        balance -= amount;
        cout << "Withdrew $" << amount << " | New balance: $" << balance << "\n";
    }

    // Check balance
    void checkBalance() {
        cout << "Account #" << accountNo << " (" << owner << ") Balance: $" << balance << "\n";
    }

    // Transfer to another account
    void transfer(BankAccount& target, double amount) {
        if (amount > balance) { cout << "Insufficient funds for transfer\n"; return; }
        balance -= amount;
        target.balance += amount;
        cout << "Transferred $" << amount << " to " << target.owner << "\n";
    }
};

int main() {
    BankAccount acc1("Alice", 1001, 500.0);
    BankAccount acc2("Bob", 1002, 200.0);

    acc1.checkBalance();
    acc2.checkBalance();
    cout << "\n";

    acc1.deposit(300);
    acc1.withdraw(100);
    acc1.withdraw(1000);
    cout << "\n";

    acc1.transfer(acc2, 250);
    acc1.checkBalance();
    acc2.checkBalance();

    return 0;
}