#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* findlca(Node* root, int n1, int n2) {
    if (!root)
        return nullptr;

    if (root->key == n1 || root->key == n2)
        return root;

    Node* l = findlca(root->left, n1, n2);
    Node* r = findlca(root->right, n1, n2);

    if (l && r)
        return root;

    return (l != nullptr) ? l : r;
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(14);
    root->left->right = new Node(15);
    root->right->left = new Node(16);
    root->right->right = new Node(17);

    int n1 = 4, n2 = 5;
    Node* lca = findlca(root, n1, n2);

    if (lca)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->key << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}

