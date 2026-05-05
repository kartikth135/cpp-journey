#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Task {
    string title;
    bool done;
};

void addTask(vector<Task>& tasks) {
    string title;
    cout << "Task title: "; cin.ignore(); getline(cin, title);
    tasks.push_back({title, false});
    cout << "Task added!\n";
}

void listTasks(vector<Task>& tasks) {
    if (tasks.empty()) { cout << "No tasks\n"; return; }
    cout << "\n--- Todo List ---\n";
    for (int i = 0; i < tasks.size(); i++)
        cout << i + 1 << ". [" << (tasks[i].done ? "X" : " ") << "] " << tasks[i].title << "\n";
}

void completeTask(vector<Task>& tasks) {
    listTasks(tasks);
    int idx;
    cout << "Mark task number as done: "; cin >> idx;
    if (idx < 1 || idx > tasks.size()) { cout << "Invalid\n"; return; }
    tasks[idx - 1].done = true;
    cout << "Task marked done!\n";
}

void deleteTask(vector<Task>& tasks) {
    listTasks(tasks);
    int idx;
    cout << "Delete task number: "; cin >> idx;
    if (idx < 1 || idx > tasks.size()) { cout << "Invalid\n"; return; }
    tasks.erase(tasks.begin() + idx - 1);
    cout << "Task deleted!\n";
}

void saveToFile(vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (Task& t : tasks)
        file << (t.done ? "1" : "0") << "|" << t.title << "\n";
    file.close();
    cout << "Saved to tasks.txt\n";
}

void loadFromFile(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    if (!file) return;
    string line;
    while (getline(file, line)) {
        if (line.size() < 3) continue;
        Task t;
        t.done = line[0] == '1';
        t.title = line.substr(2);
        tasks.push_back(t);
    }
    file.close();
    cout << "Tasks loaded!\n";
}

int main() {
    vector<Task> tasks;
    loadFromFile(tasks);
    int choice;

    cout << "=== Todo List ===\n";
    while (true) {
        cout << "\n1.Add  2.List  3.Complete  4.Delete  5.Save  6.Exit\n";
        cout << "Choice: "; cin >> choice;
        if      (choice == 1) addTask(tasks);
        else if (choice == 2) listTasks(tasks);
        else if (choice == 3) completeTask(tasks);
        else if (choice == 4) deleteTask(tasks);
        else if (choice == 5) saveToFile(tasks);
        else { saveToFile(tasks); cout << "Goodbye!\n"; break; }
    }
    return 0;
}