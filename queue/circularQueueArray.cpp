#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the queue

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue operation (insert element)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE; // circular increment
        }

        arr[rear] = value;
        cout << value << " enqueued into queue." << endl;
    }

    // Dequeue operation (remove element)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }

        int deletedValue = arr[front];

        // If only one element
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE; // circular increment
        }

        cout << deletedValue << " dequeued from queue." << endl;
        return deletedValue;
    }

    // Peek front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // full now
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70); // reuses freed spaces
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
