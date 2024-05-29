#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

bool iden(Node* r1, Node* r2) {
    if (!r1 && !r2)
        return true;

    if (r1 && r2) {
        return (r1->key == r2->key) &&
               iden(r1->left, r2->left) &&
               iden(r1->right, r2->right);
    }

    return false;
}

int main() {
    Node* r1 = new Node(11);
    r1->left = new Node(12);
    r1->right = new Node(13);
    r1->left->left = new Node(14);
    r1->left->right = new Node(15);

    Node* r2 = new Node(11);
    r2->left = new Node(12);
    r2->right = new Node(13);
    r2->left->left = new Node(14);
    r2->left->right = new Node(15);

    if (iden(root1, root2))
        cout << "Trees are identical." << endl;
    else
        cout << "Trees are not identical." << endl;

    return 0;
}

