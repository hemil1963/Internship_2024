#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

pair<bool, int> isbal(Node* n) {
    if (n == nullptr)
        return make_pair(true, 0);

    pair<bool, int> l = isbal(n->left);
    pair<bool, int> r = isbal(n->right);

    bool b = l.first && r.first && abs(l.second - r.second) <= 1;
    int h = max(l.second, r.second) + 1;

    return make_pair(b, h);
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(14);
    root->left->right = new Node(15);
root->left->right->right = new Node(15);

    pair<bool, int> ans = isbal(root);

    if (ans.first)
        cout << "Balanced tree." << endl;
    else
        cout << "Unbalanced tree." << endl;

    return 0;
}

