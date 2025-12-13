#include<iostream>
using namespace std;

struct node{
    int key;
    node*next;
};

class separateChaining{
    public:

    int size;
    node**table;

    separateChaining(int s){
        size=s;
        table=new node*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        } 
    }

    int hash(int key){
        return key % size;
    }

    void insert(int key){
        int index=hash(key);
        node*newnode=new node{key,NULL};

        if(table[index]==NULL){
            table[index]=newnode;
        }
        else{
            newnode->next=table[index];
            table[index]=newnode;
        }
    }

    void deletekey(int key){
        int index=hash(key);
        node*curr=table[index];
        node*prev=NULL;

        while(curr!=NULL){
            if(curr->key==key){
                if(prev==NULL){
                    table[index]=curr->next;
                }
                else{
                    prev->next=curr->next;
                }
                delete curr;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
    }
    bool searchkey(int key){
        int index=hash(key);
        node*curr=table[index];

        while(curr!=NULL){
            if(curr->key==key){
                cout<< key<<"found"<< endl;
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    void display(){
        for(int i=0;i<size;i++){
            node*curr=table[i];
            cout<<i<<":";
            while(curr!=NULL){
                cout<<curr->key<<"->";
                curr=curr->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};
