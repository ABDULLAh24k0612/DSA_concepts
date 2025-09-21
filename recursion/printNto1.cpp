#include <iostream>
using namespace std;

void printDescending(int n) {
    if (n == 0) return; // base case
    cout << n << " ";
    printDescending(n - 1); // recursive call
}

int main() {
    int n = 5;
    cout << "Numbers from " << n << " down to 1: ";
    printDescending(n);
    cout << endl;
    return 0;
}
