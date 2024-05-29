#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int value) : val(value), next(nullptr) {}
};

class CustomLinkedList {
private:
    Node* head;

public:
    CustomLinkedList() : head(nullptr) {}

    void pushFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    int getMiddle() {
        if (head == nullptr) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->val;
    }


};

int main() {
    CustomLinkedList ll;

    for (int i = 21; i <= 29; ++i) {
        ll.pushFront(i);
    }

    int middleElement = ll.getMiddle();
    cout << "Middle Element: " << middleElement << endl;

    return 0;
}

