#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

class HashTable {
    int size;
    Node** table;

public:
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hash(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int index = hash(key);
        Node* newNode = new Node{key, NULL};

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    bool searchKey(int key) {
        int index = hash(key);
        Node* curr = table[index];

        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = NULL;

        while (curr) {
            if (curr->key == key) {
                if (prev == NULL)
                    table[index] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable h(10);

    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);

    h.display();
}
