#include <iostream>
using namespace std;
class Cqu {
private:
    int *arr;
    int front, rear, cap;

public:
    Cqu(int size) {
        cap = size + 1;
        arr = new int[cap];
        front = rear = 0;
    }

    void enq(int item) {
        if (full()) {
            cout << "Queue is full.\n";
            return;
        }

        arr[rear] = item;
        rear = (rear + 1) % cap;

    }

    void deq() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        int item = arr[front];
        front = (front + 1) % cap;

    }

    bool empty() {
        return front == rear;
    }

    bool full() {
        return (rear + 1) % cap == front;
    }

    void display() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        } while (i != rear);
        cout << "\n";
    }
};

int main() {
    Cqu cq(5);

    cq.enq(1);
    cq.enq(2);
    cq.display();
    cq.deq();
    cq.deq();
    cq.display();
    cq.enq(6);
    cq.enq(7);

    cq.display();

    return 0;
}

