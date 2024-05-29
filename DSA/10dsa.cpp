#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class CustomLinkedList {
private:
    Node* start;

public:
    CustomLinkedList() : start(nullptr) {}

    void addToFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = start;
        start = newNode;
    }

    void reverseList() {
        Node* previous = nullptr;
        Node* current = start;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        start = previous;
    }

    void displayList() {
        Node* current = start;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }


};

int main() {
    CustomLinkedList ll;

    for (int i = 1; i <= 5; ++i) {
        ll.addToFront(i);
    }

    cout << "Initial List: ";
    ll.displayList();

    ll.reverseList();

    cout << "Reversed List: ";
    ll.displayList();

    return 0;
}

