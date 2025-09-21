#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
    if (start >= end) return;           // base case
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);  // recursive call
}

int main() {
    string s = "hello";
    reverseString(s, 0, s.length() - 1);
    cout << "Reversed string: " << s << endl;
    return 0;
}
