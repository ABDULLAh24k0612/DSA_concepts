#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    if (start >= end) return true; // base case: crossed or equal indices
    if (str[start] != str[end]) return false; // mismatch
    return isPalindrome(str, start + 1, end - 1); // recursive check
}

int main() {
    string s = "radar";
    if (isPalindrome(s, 0, s.length() - 1))
        cout << s << " is a palindrome" << endl;
    else
        cout << s << " is not a palindrome" << endl;

    return 0;
}
