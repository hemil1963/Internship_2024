#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

void insertNode(node* &head, int val) {
    node* newNode = new node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return;
}

node* intersectionPresent(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;

    while (d1 != d2) {
        d1 = (d1 == NULL) ? head2 : d1->next;
        d2 = (d2 == NULL) ? head1 : d2->next;
    }

    return d1;
}

void printList(node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main() {

    node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node* head1 = head;
    head = head->next->next->next;


    node* headSec = NULL;
    insertNode(headSec, 1);
    insertNode(headSec, 3);

    node* head2 = headSec;
    headSec->next->next = head;

    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    node* answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;

    return 0;
}
