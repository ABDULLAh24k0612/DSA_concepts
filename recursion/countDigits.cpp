#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 0;            // base case
    return 1 + countDigits(n / 10);  // recursive call
}

int main() {
    int num = 12345;
    cout << "Number of digits in " << num << " is " << countDigits(num) << endl;
    return 0;
}
