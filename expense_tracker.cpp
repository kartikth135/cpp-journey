#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Expense {
    string description;
    string category;
    double amount;
};

class ExpenseTracker {
    vector<Expense> expenses;

public:
    void addExpense(string desc, string cat, double amount) {
        expenses.push_back({desc, cat, amount});
        cout << "Added: " << desc << " (" << cat << ") - $" << fixed << setprecision(2) << amount << "\n";
    }

    void listAll() {
        if (expenses.empty()) { cout << "No expenses\n"; return; }
        cout << "\n--- All Expenses ---\n";
        cout << left << setw(20) << "Description"
             << setw(15) << "Category"
             << "Amount\n";
        cout << string(45, '-') << "\n";
        for (Expense& e : expenses)
            cout << left << setw(20) << e.description
                 << setw(15) << e.category
                 << "$" << fixed << setprecision(2) << e.amount << "\n";
    }

    void filterByCategory(string cat) {
        cout << "\n--- Category: " << cat << " ---\n";
        double total = 0;
        bool found = false;
        for (Expense& e : expenses) {
            if (e.category == cat) {
                cout << e.description << " - $" << fixed << setprecision(2) << e.amount << "\n";
                total += e.amount;
                found = true;
            }
        }
        if (!found) cout << "No expenses in this category\n";
        else cout << "Total: $" << fixed << setprecision(2) << total << "\n";
    }

    void summary() {
        if (expenses.empty()) { cout << "No expenses\n"; return; }
        double total = 0;
        cout << "\n--- Summary by Category ---\n";
        vector<string> seen;
        for (Expense& e : expenses) {
            if (find(seen.begin(), seen.end(), e.category) == seen.end())
                seen.push_back(e.category);
        }
        for (string& cat : seen) {
            double catTotal = 0;
            for (Expense& e : expenses)
                if (e.category == cat) catTotal += e.amount;
            cout << left << setw(15) << cat << "$" << fixed << setprecision(2) << catTotal << "\n";
            total += catTotal;
        }
        cout << string(25, '-') << "\n";
        cout << left << setw(15) << "TOTAL" << "$" << fixed << setprecision(2) << total << "\n";
    }
};

int main() {
    ExpenseTracker tracker;

    tracker.addExpense("Groceries",    "Food",      85.50);
    tracker.addExpense("Netflix",      "Entertainment", 15.99);
    tracker.addExpense("Bus pass",     "Transport", 45.00);
    tracker.addExpense("Dinner out",   "Food",      62.30);
    tracker.addExpense("Gym",          "Health",    30.00);
    tracker.addExpense("Spotify",      "Entertainment", 9.99);
    tracker.addExpense("Taxi",         "Transport", 18.50);
    tracker.addExpense("Coffee",       "Food",      12.75);

    tracker.listAll();
    tracker.filterByCategory("Food");
    tracker.summary();

    return 0;
}