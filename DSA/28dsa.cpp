#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

int findh(Node* node) {
    if (node == nullptr)
        return 0;
    else {
        int lefth = findh(node->left);
        int righth = findh(node->right);
        return max(lefth, righth) + 1;
    }
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(14);
    root->left->right = new Node(15);

    int height = findh(root);

    cout << "Height of the binary tree: " << height << endl;

    return 0;
}

