#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node* root) {
    stack<Node*> s;
    Node* p = root;

    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }

        p = s.top();
        s.pop();

        cout << p->key << " ";

        p = p->right;
    }
}

int main() {

    Node* root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(13);


    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

