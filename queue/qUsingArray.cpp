#include <iostream>
using namespace std;

class Queue {
public:
    int size;
    int* arr;
    int front;
    int rear;
    int count;  // track number of elements

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (count == size) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % size;
        count--;
        return x;
    }

    int getFront() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front is: " << q.getFront() << endl;

    cout << "Popped el is : " << q.dequeue() << endl;
    cout << "Front is: " << q.getFront() << endl;

    q.enqueue(60);  // This will now work due to circular logic

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
