
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    
    Queue() {
        front = rear = nullptr;
    }

   
    bool isEmpty() {
        return (front == nullptr);
    }

    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued into queue." << endl;
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;
        delete temp;

       
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << value << " dequeued from queue." << endl;
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

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
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
    q.display();

    return 0;
}
