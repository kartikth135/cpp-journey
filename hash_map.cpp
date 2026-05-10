#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashMap {
    int capacity;
    list<pair<string, int>>* table;

    int hashFunc(string key) {
        int hash = 0;
        for (char c : key) hash = (hash * 31 + c) % capacity;
        return hash;
    }

public:
    HashMap(int cap = 10) : capacity(cap) {
        table = new list<pair<string, int>>[capacity];
    }

    // Insert or update key
    void put(string key, int val) {
        int idx = hashFunc(key);
        for (auto& p : table[idx]) {
            if (p.first == key) { p.second = val; return; }
        }
        table[idx].push_back({key, val});
        cout << "Inserted: " << key << " -> " << val << "\n";
    }

    // Get value by key
    int get(string key) {
        int idx = hashFunc(key);
        for (auto& p : table[idx])
            if (p.first == key) return p.second;
        cout << key << " not found\n";
        return -1;
    }

    // Remove key
    void remove(string key) {
        int idx = hashFunc(key);
        table[idx].remove_if([&](pair<string,int>& p) {
            return p.first == key;
        });
        cout << key << " removed\n";
    }

    // Display all entries
    void display() {
        cout << "\n--- HashMap ---\n";
        for (int i = 0; i < capacity; i++) {
            if (table[i].empty()) continue;
            cout << "Bucket " << i << ": ";
            for (auto& p : table[i])
                cout << "[" << p.first << ":" << p.second << "] ";
            cout << "\n";
        }
    }

    ~HashMap() { delete[] table; }
};

int main() {
    HashMap map;

    map.put("apple", 10);
    map.put("banana", 20);
    map.put("cherry", 30);
    map.put("date", 40);
    map.put("elderberry", 50);

    map.display();

    cout << "\nGet apple: " << map.get("apple") << "\n";
    cout << "Get mango: " << map.get("mango") << "\n";

    map.put("apple", 99);
    cout << "Updated apple: " << map.get("apple") << "\n";

    map.remove("banana");
    map.display();

    return 0;
}