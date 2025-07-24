#include<bits/stdc++.h>
using namespace std;

//considering 0 based indexing

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        next = prev = NULL;

    }
};

void insert(Node* &head,int val, int pos){
    Node* nodeToBeInserted = new Node(val);
    if(head == NULL || pos <0 ){
        cout << "invalid pos or no linked list";
        return;
    }

    if(pos == 0){
        nodeToBeInserted->next = head;
        if (head) head->prev = nodeToBeInserted;
        head = nodeToBeInserted;
        return;
    }

    
    Node* temp = head;
    for(int i = 0; i<pos-1 && temp != NULL ; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "Not possible to insert";
        return;
    }
    Node* nextNode = temp->next;
    temp->next = nodeToBeInserted;
    nodeToBeInserted->next = nextNode;
    nodeToBeInserted->prev = temp;
    nextNode->prev = nodeToBeInserted;
}


void deleteNode(Node* &head, int pos){
     if(head == NULL || pos < 0 ){
        cout << "invalid pos or no linked list";
        return;
    }

    if(pos == 0){
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete toDelete;
        return;
    }


    Node* temp = head;
    for(int i = 0; i<pos-1 && temp!=NULL ; i++){
        temp = temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        cout << "Not possible to delete";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    toDelete->prev = temp;
    delete toDelete;

}



void printLL(Node* node){
    while(node){
        if(node->next == NULL){
             cout << node->val;
        }
        else cout << node->val << " <-> ";
        node=node->next;
    }
    cout << endl;
}


int main(){
    Node* head = new Node(10);
    Node* x = new Node(20);
    Node* y = new Node(30);
    head->next = x;
    x->prev = head;
    x->next = y;
    y->prev = x;

    printLL(head);

    insert(head,25,0);//0 based

    printLL(head);

    deleteNode(head,0);

    printLL(head);



    return 0;
}