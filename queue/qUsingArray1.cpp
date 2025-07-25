#include<iostream>
using namespace std;


class Queue{
public:
    int size;
    int front;
    int rear;
    int *arr;
    int cnt ;

    Queue(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
        cnt = 0;
    }

    void push(int num){
        if(cnt == size){
            cout << "Queue is full" << endl;
            return;
        }
        if(cnt==0){
            front++;
            rear++;
        }else{
            rear++;
        }
        arr[rear] = num;
        cnt++;
    }

    int pop(){
        if(cnt == 0){
            cout << "Ququ is empty" << endl;
            return -1;
        }
        int x = arr[front];
        front = front +1;
        cnt--;
        return x;
    }

    void display(){
        for(int i = front; i<=rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int top(){
         if(cnt == 0){
            cout << "Ququ is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};


int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();

    cout << q.pop() << endl;
    q.display();

    cout << q.top() << endl;

    return 0;
}