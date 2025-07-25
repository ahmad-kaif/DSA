#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> s1, s2;

    Queue() {}

    void push(int num) {
        // Move all elements to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element onto s1
        s1.push(num);

        // Restore the original order
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }

    void display() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Temporary stack to preserve original
        stack<int> temp = s1;
        stack<int> rev;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }

        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();           // 10 20 30 40
    cout << q.pop() << endl; // 10
    q.display();           // 20 30 40
    cout << q.front() << endl; // 20

    return 0;
}
