#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    void push(int num) {
        q1.push(num);
        // Move all previous elements from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        if (q2.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int x = q2.front();
        q2.pop();
        cout << "Popped item: " << x << endl;
        return x;
    }

    void display() {
        if (q2.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        queue<int> temp = q2;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();     // should print: 30 20 10
    s.pop();         // should remove 30
    s.display();     // should print: 20 10
    return 0;
}
