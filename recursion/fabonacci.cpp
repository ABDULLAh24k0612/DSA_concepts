#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0; // base case 0th Fibonacci number
    if (n == 1) return 1; // base case 1st Fibonacci number
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive calls
}

int main() {
    int n = 7;
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    return 0;
}
