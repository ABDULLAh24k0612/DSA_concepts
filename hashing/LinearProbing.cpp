#include <iostream>
using namespace std;

class LinearHash {
    int size;
    int* table;
    int EMPTY = -1;

public:
    LinearHash(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    int hash(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int index = hash(key);

        while (table[index] != EMPTY)
            index = (index + 1) % size;

        table[index] = key;
    }

    bool searchKey(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) return true;
            index = (index + 1) % size;

            if (index == start) return false;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = EMPTY;
                return;
            }
            index = (index + 1) % size;
            if (index == start) return;
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    LinearHash h(10);
    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);

    h.display();
}
