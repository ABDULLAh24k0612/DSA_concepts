#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s) {
    Stack st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop(); // remove '('
        } else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.pop();
    }

    return result;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '('){
         infix[i] = ')';
        }
        else if (infix[i] == ')') {
        infix[i] = '(';
        }
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix = "(A+B)*C-D";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}
