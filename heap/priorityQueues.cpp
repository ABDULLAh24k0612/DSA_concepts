#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() { size = 0; }

    void push(int val) {
        size++;
        arr[size] = val;

        int i = size;
        while (i > 1 && arr[i] > arr[i/2]) {
            swap(arr[i], arr[i/2]);
            i = i/2;
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[1];
    }

    void pop() {
        if (size == 0) return;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2*i;
            int right = 2*i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;
            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest == i) break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Top element: " << pq.top() << endl; // 50
    pq.pop();

    cout << "Top after pop: " << pq.top() << endl; // 20
}
