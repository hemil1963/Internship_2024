#include <iostream>
#include <unordered_set>
using namespace std;


struct Node
{
    int data;
    Node* next;
};


void printList(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << " —> ";
        ptr = ptr->next;
    }

    cout << "nullptr";
}


void push(Node** headRef, int data)
{
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}


void removeDuplicates(Node* head)
{
    Node* previous = nullptr;
    Node* current = head;

    unordered_set<int> set;
    while (current != nullptr)
    {
        if (set.find(current->data) != set.end()) {
            previous->next = current->next;
        }
        else {

            set.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}

int main()
{

    int keys[] = {5, 3, 4, 2, 5, 4, 1, 3};
    int n = sizeof(keys)/sizeof(keys[0]);
    Node* head = nullptr;
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    removeDuplicates(head);
    printList(head);

    return 0;
}
