#include <iostream>
using namespace std;

class Stack {
public:
    int topIndex;
    int size;
    int* arr;

    Stack(int size) {
        this->size = size;
        topIndex = -1;
        arr = new int[size];
    }

    void push(int x) {
        if (topIndex >= size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return -1; // Or throw an error
        }
        int x = arr[topIndex];
        topIndex--;
        return x;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    void display() {
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output: 10 20 30

    cout << "Top: " << s.top() << endl; // Output: Top: 30

    s.pop();
    s.display(); // Output: 10 20

    return 0;
}
