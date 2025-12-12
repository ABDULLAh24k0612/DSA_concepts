#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[100];
    int size;

    MinHeap() { size = 0; }

    void insert(int val) {
        size++;
        arr[size] = val;

        int i = size;
        while (i > 1 && arr[i] < arr[i/2]) {
            swap(arr[i], arr[i/2]);
            i = i/2;
        }
    }

    int removeMin() {
        if (size == 0) return -1;

        int minVal = arr[1];

        arr[1] = arr[size];
        size--;

        int i = 1;

        while (true) {
            int left = 2*i;
            int right = 2*i + 1;
            int smallest = i;

            if (left <= size && arr[left] < arr[smallest])
                smallest = left;
            if (right <= size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(arr[i], arr[smallest]);
            i = smallest;
        }

        return minVal;
    }

    void printHeap() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(30);

    cout << "Min Heap: ";
    h.printHeap();

    cout << "Removed min: " << h.removeMin() << endl;

    cout << "Min Heap after removal: ";
    h.printHeap();
}
