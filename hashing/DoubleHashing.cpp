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
            table[i] = NULL;
    }

    int h1(int key) {
        return key % size;
    }

    int h2(int key) {
        return 7 - (key % 7);  
    }

    void insertKey(int key) {
        int u = h1(key);
        int v = h2(key);

        int i = 0;
        while (table[(u + i * v) % size] != EMPTY){
            i++;
        }

        table[(u + i * v) % size] = key;
    }

    bool searchKey(int key) {
        int u = h1(key);
        int v = h2(key);

        int i = 0;
        while (table[(u + i * v) % size] != EMPTY) {
            if (table[(u + i * v) % size] == key)
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
