#include<iostream>
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

    int peekstack(){
      if(top<0){
        cout << " stack is empty "<< endl;
        return -1;
      }
      cout << arr[top] <<" is the peek of the stack"<< endl;
      return arr[top];
    }

    bool isempty(){
        return (top<0);
    }
    bool isfull(){
        return (top>=max-1);
    }
    int size(){
        cout << top+1 << " is the size of the stack"<< endl;
        return top+1;
    }
    void display(){
        if((isempty())){
            cout<< " stack is empty"<< endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<< arr[i]<< " ";
        }
        cout <<endl;
    }
}; 
int main(){

    stack s;
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(50);
    s.display();
    s.pop();
    s.pop();
    s.isempty();
    s.isfull();
    s.peekstack();
    s.size();
    s.display();

    return 0;
}
