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
}; 

int evaluatePostfix(string exp) {
    stack st;
    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val2 = st.pop();
            int val1 = st.pop();
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    string postfix = "231*+9-";
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
