#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void levelOrder(Node* root) {
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->key << " ";
        q.pop();

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(14);
    root->left->right = new Node(15);

    cout << "Level-order traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}

