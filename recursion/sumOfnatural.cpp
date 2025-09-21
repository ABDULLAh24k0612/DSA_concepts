#include <iostream>
using namespace std;

int sumNatural(int n) {
    if (n == 0) return 0; // base case
    return n + sumNatural(n - 1); // recursive call
}

int main() {
    int n = 10;
    cout << "Sum of first " << n << " natural numbers is " << sumNatural(n) << endl;
    return 0;
}
