#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() { size = 0; }

    void insert(int val) {
        size++;
        arr[size] = val;

        int i = size;
        while (i > 1 && arr[i] > arr[i/2]) {
            swap(arr[i], arr[i/2]);
            i = i/2;
        }
    }

    int removeMax() {
        if (size == 0) return -1;

        int maxVal = arr[1];
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

        return maxVal;
    }

    void printHeap() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(50);
    h.insert(20);
    h.insert(30);
    h.insert(10);

    cout << "Max Heap: ";
    h.printHeap();

    cout << "Removed max: " << h.removeMax() << endl;

    cout << "Max Heap after removal: ";
    h.printHeap();
}

