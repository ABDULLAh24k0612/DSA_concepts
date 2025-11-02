#include<iostream>
using namespace std;

struct node{
    public:

    int data;
    node*next;
};

class stack{

    private:

    node* top;
    
    public:
    stack(){
        top=nullptr;
     }


void push(int data){
    node*newnode=new node();
    newnode->data=data;
    newnode->next=top;
    top=newnode;
    cout << newnode->data << " pushed into the stack"<< endl;

}
bool isempty(){
    return (top==nullptr);
}
int pop(){
    if(isempty()){
        return -1;
    }
    node*temp=top;
    int popped=temp->data;
    top=top->next;
    delete temp;
    cout << popped <<" is popped out of the stack"<< endl;
    return popped;
}

int peek(){
    if(isempty()){
        return -1;
    }
    cout << top->data<<" is the top of the stack "<< endl;
    return top->data;
}
int size(){
    int size=0;
    node*temp=top;
    while(temp->next!=nullptr){
      temp=temp->next;
      size++;
    }
    cout << size << " is the size of the stack" << endl;
    return size;
}

void display() {
        if (isempty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack (top → bottom): ";
        node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    ~stack() {
        while (!isempty()) {
            pop();
        }
    }
};



int main(){
    

    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek() ;
    s.pop() ;
    s.display();
    s.isempty() ;

    return 0;
}

