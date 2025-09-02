#include <bits/stdc++.h>
using namespace std;

class UnorderedMap {
    static const int SIZE = 1000; // table size
    vector<pair<int, string>> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE; // simple mod
    }

public:
    void insert(int key, string value) {
        int idx = hashFunction(key);
        // check if key exists
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value; // update
                return;
            }
        }
        table[idx].push_back({key, value}); // insert new
    }

    string get(int key) {
        int idx = hashFunction(key);
        for (auto &p : table[idx]) {
            if (p.first == key) return p.second;
        }
        return "Not Found";
    }

    void erase(int key) {
        int idx = hashFunction(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if (it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }
};

int main() {
    UnorderedMap um;
    um.insert(1, "Apple");
    um.insert(2, "Banana");
    um.insert(1001, "Mango"); // collision with key=1 if SIZE=1000

    cout << um.get(1) << endl;     // Apple
    cout << um.get(1001) << endl;  // Mango
    um.erase(2);
    cout << um.get(2) << endl;     // Not Found
}
