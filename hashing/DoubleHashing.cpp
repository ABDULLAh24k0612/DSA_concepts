#include <iostream>
using namespace std;

class DoubleHash {
    int size;
    int* table;
    int EMPTY = -1;

public:
    DoubleHash(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    int h1(int key) {
        return key % size;
    }

    int h2(int key) {
        return 7 - (key % 7);  // must be non-zero
    }

    void insertKey(int key) {
        int index = h1(key);
        int step = h2(key);

        int i = 0;
        while (table[(index + i * step) % size] != EMPTY)
            i++;

        table[(index + i * step) % size] = key;
    }

    bool searchKey(int key) {
        int index = h1(key);
        int step = h2(key);

        int i = 0;
        while (table[(index + i * step) % size] != EMPTY) {
            if (table[(index + i * step) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    DoubleHash h(10);
    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);

    h.display();
}
