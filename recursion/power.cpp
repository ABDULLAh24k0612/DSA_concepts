#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1;            // base case
    return x * power(x, n - 1);      // recursive call
}

int main() {
    int base = 2, exponent = 5;
    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;
    return 0;
}
