#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Popped EL: " << s.pop() << endl;
    cout << "Top is: " << s.top() << endl;

    return 0;
}
