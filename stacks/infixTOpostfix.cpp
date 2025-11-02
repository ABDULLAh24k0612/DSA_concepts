#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define max 100

class stack{
    private:

    int top; 
    int arr[max];

    public:

    stack(){
        top=-1;
    }
  
    void push(int x){
        if(top>=max-1){
            cout <<" stack is full and over flow"<< endl;
            return;
        }
        arr[++top]=x;
        cout << x << " pushed into the stack"<< endl;
    }

    int pop(){
        if(top<0){
            cout << " stack is empty and underflow"<<endl;
            return -1;
        }
        int popped=arr[top];
        top--;
        cout << popped << " popped out of the stack"<< endl;
        return popped;
    }

    bool isempty(){
        return (top<0);
    }
     int peek(){
      if(top<0){
        cout << " stack is empty "<< endl;
        return -1;
      }
      cout << arr[top] <<" is the peek of the stack"<< endl;
      return arr[top];
    }

}; 


int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s) {
    stack st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isempty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop(); 
        } else { 
            while (!st.isempty() && precedence(st.peek()) >= precedence(c)) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isempty()) {
        result += st.pop();
    }

    return result;
}

int main() {
    string infix = "(A+B)*C-D";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
