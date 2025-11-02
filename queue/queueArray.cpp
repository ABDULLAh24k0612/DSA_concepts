#include <iostream>
using namespace std;

#define SIZE 5   

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    
    Queue() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

 
    bool isFull() {
        return (rear == SIZE - 1);
    }


    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) {
        front = 0; 
        }
        rear++;
        arr[rear] = value;
        cout << value << " enqueued into queue." << endl;
        }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }
        int deletedValue = arr[front];
        front++;
        cout << deletedValue << " dequeued from queue." << endl;
        return deletedValue;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 

    q.display();

    return 0;
}
