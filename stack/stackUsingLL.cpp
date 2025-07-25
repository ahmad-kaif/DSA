#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            next = NULL;
        }
    };

    Node* head = NULL;

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (head == NULL) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int poppedValue = head->val;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return poppedValue;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->val;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node* curr = head;
        cout << "Stack elements (top to bottom): ";
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Should print: 30 20 10

    cout << "Top: " << s.top() << endl; // 30

    cout << "Popped: " << s.pop() << endl; // 30
    s.display(); // Should print: 20 10

    cout << "Popped: " << s.pop() << endl; // 20
    cout << "Popped: " << s.pop() << endl; // 10
    cout << "Popped: " << s.pop() << endl; // Underflow

    return 0;
}
