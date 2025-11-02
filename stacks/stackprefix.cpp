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


int evaluatePrefix(string exp) {
    stack st;
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val1 = st.pop();
            int val2 = st.pop();
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
    string prefix = "-+2*319";
    cout << "Prefix: " << prefix << endl;
    cout << "Evaluated Result: " << evaluatePrefix(prefix) << endl;
    return 0;
}
