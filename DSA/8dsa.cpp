#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class CustomLinkedList {
private:
    ListNode* head;

public:
    CustomLinkedList() : head(nullptr) {}

    void insertAtStart(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    void removeNode(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->val == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* current = head;
        while (current->next != nullptr && current->next->val != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void displayList() {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~CustomLinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    CustomLinkedList ll;

    ll.insertAtStart(33);
    ll.insertAtStart(202);
    ll.insertAtStart(103);

    cout << "Initial List: ";
    ll.displayList();

    ll.removeNode(202);

    cout << "List after removal: ";
    ll.displayList();

    return 0;
}
