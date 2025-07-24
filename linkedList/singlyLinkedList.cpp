#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }

   
};

void printLL(Node* node){
        while(node){
            cout << node->val << " -> ";
            node=node->next;
        }
        cout << endl;
}

void insert(Node*& head, int val, int pos){
    Node* nodeToBeInserted = new Node(val);
    if (pos == 1){
        nodeToBeInserted->next = head;
        head = nodeToBeInserted;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL) return;
    nodeToBeInserted->next = temp->next;
    temp->next = nodeToBeInserted;
}


void deleteNode(Node*& head, int pos){
    if (head == NULL || pos <= 0) return;

    if (pos == 1){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}


int main(){
    Node* x = new Node(10);
    Node* y = new Node(20);
    Node* z = new Node(30);
    Node* p = new Node(40);
    // Node* q = new Node(50);
    x->next = y;
    y->next = z;
    z->next = p;
    // p->next = q;

    printLL(x);

    //insert 35 betwwn 30 and 40 -- at 4th pos apart from head
    // // thsi will work from pos >= 2(1 based indexing)
    // insert(x,35,2);
    // printLL(x);

    // //for head insertiuon
    // Node* newHead = insertAtHead(x,5);
    // printLL(newHead);


    //delete any node except head from >=2 node(1-based)
    // deleteNode(x,3);
    // printLL(x);

    //same to delete head new function




    return 0;
}