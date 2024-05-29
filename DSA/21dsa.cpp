#include <iostream>

class Queue {
private:
    int front, rear, capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        arr = new int[size];
    }

    void enq(int item) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = item;
        cout << item << " enqueu\n";
    }

    void deq() {
        if (isEmpty()) {
            cout << "Queue is empty \n";
            return;
        }

        int item = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        cout << item << " dequeue\n";
    }

    bool empty() {
        return front == -1;
    }

    bool full() {
        return (rear + 1) % capacity == front;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << "\n";
    }
};

int main() {
    Queue q(5);

    q.enq(1);
    q.enq(2);
    q.enq(3);

    q.display();

    q.deq();
    q.display();

    q.enq(4);
    q.enq(5);
    q.enq(6);

    q.display();

    return 0;
}

