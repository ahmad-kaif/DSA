#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    string value;
    Node* left;
    Node* right;

    Node(int k, string v) {
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
};

class OrderedMap {
    Node* root;

    Node* insert(Node* node, int key, string value) {
        if (node == NULL) return new Node(key, value);

        if (key < node->key) node->left = insert(node->left, key, value);
        else if (key > node->key) node->right = insert(node->right, key, value);
        else node->value = value; // update if key exists

        return node;
    }

    Node* search(Node* node, int key) {
        if (node == NULL || node->key == key) return node;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->key << " : " << node->value << endl;
        inorder(node->right);
    }

public:
    // Simple constructor
    OrderedMap() {
        root = NULL;
    }

    void insert(int key, string value) {
        root = insert(root, key, value);
    }

    string get(int key) {
        Node* res = search(root, key);
        if (res != NULL) return res->value;
        return "Not Found";
    }

    void printInOrder() {
        inorder(root);
    }
};

int main() {
    OrderedMap om;
    om.insert(3, "Banana");
    om.insert(1, "Apple");
    om.insert(2, "Mango");

    cout << "Search 2: " << om.get(2) << endl; // Mango
    cout << "\nIn-order Traversal (sorted keys):\n";
    om.printInOrder();

    return 0;
}
