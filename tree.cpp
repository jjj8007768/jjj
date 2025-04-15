#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

class Traversal {
public:
    void inOrderTraversal(Node* root) {
        if (root == nullptr) return;
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (root == nullptr) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    void DoubleOrderTraversal(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        DoubleOrderTraversal(root->left);
        cout << root->data << " ";
        DoubleOrderTraversal(root->right);
    }

    void TripleOrderTraversal(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        TripleOrderTraversal(root->left);
        cout << root->data << " ";
        TripleOrderTraversal(root->right);
        cout << root->data << " ";
    }

    void levelOrderTraversal(Node* root) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
};

int main() {
    Node* root = new Node(65);
    root->left = new Node(66);
    root->right = new Node(67);
    root->left->left = new Node(68);
    root->left->right = new Node(69);
    root->right->left = new Node(70);

    Traversal t;

    cout << "In-Order Traversal: ";
    t.inOrderTraversal(root);
    cout << endl;

    cout << "Pre-Order Traversal: ";
    t.preOrderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    t.postOrderTraversal(root);
    cout << endl;

    cout << "Double-Order Traversal: ";
    t.DoubleOrderTraversal(root);
    cout << endl;

    cout << "Triple-Order Traversal: ";
    t.TripleOrderTraversal(root);
    cout << endl;

    cout << "Level-Order Traversal: ";
    t.levelOrderTraversal(root);
    cout << endl;

    return 0;
}
