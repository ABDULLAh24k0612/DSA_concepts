#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;           // base case
    return gcd(b, a % b);            // recursive call
}

int main() {
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
