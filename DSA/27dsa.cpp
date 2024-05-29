#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node) {
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(14);
    root->left->right = new Node(15);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}

