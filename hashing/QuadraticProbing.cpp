#include <iostream>
using namespace std;

class QuadraticHash {
    int size;
    int* table;
    int EMPTY = -1;

public:
    QuadraticHash(int s) {
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

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == EMPTY) {
                table[newIndex] = key;
                return;
            }
        }
    }

    bool searchKey(int key) {
        int index = hash(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;

            if (table[newIndex] == EMPTY)
                return false;

            if (table[newIndex] == key)
                return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    QuadraticHash h(10);
    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);
    
    h.display();
}
