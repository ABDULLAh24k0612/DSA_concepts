#include <iostream>
#include <string>
using namespace std;


void rabinKarpSearch(const string &text, const string &pattern) {

    int n = text.length();     
    int m = pattern.length(); 

    if (m > n) {
        cout << "Pattern is longer than text — no match." << endl;
        return;
    }

    int base = 256;  
    int prime = 101;
    int patternHash = 0;
    int textHash = 0;   
    int highestBase = 1; 

    for (int i = 0; i < m - 1; i++) {
        highestBase = (highestBase * base) % prime;
    }

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % prime;
        textHash = (textHash * base + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {

        if (patternHash == textHash) {

            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n - m) {
            textHash = (textHash - text[i] * highestBase) % prime; 
            textHash = (textHash * base + text[i + m]) % prime;   

            if (textHash < 0) {
                textHash += prime;
            }
        }
    }
}

int main() {

    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    rabinKarpSearch(text, pattern);

    return 0;
}
