#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    
    CircularQueue() {
        front = rear = nullptr;
    }

   
    bool isEmpty() {
        return (front == nullptr);
    }

    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            front = rear = newNode;
            newNode->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }

        cout << value << " enqueued into circular queue." << endl;
    }

   
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }

        int value;
        
        if (front == rear) {
            value = front->data;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            value = temp->data;
            front = front->next;
            rear->next = front;  
            delete temp;
        }

        cout << value << " dequeued from circular queue." << endl;
        return value;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
