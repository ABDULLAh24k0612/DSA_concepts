#include<iostream>
using namespace std;

class doublehash{
    public:

    int size;
    int*table;

    doublehash(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
    }

    int hash1(int key){
        return key%size;
    }

    int hash2(int key){
        return 7-(key%7);
    }

    void insert(int key){
       int u=hash1(key);
       int v=hash2(key);
        
        for(int i=0;i<size;i++){
            int newindex=(u+i*v)%size;
            if(table[newindex]==NULL){
                table[newindex]=key;
                break;
            }
        }
    }
    
    void deletekey(int key){
        int u=hash1(key);
       int v=hash2(key);

        for(int i=0;i<size;i++){
            int newindex=(u+i*v)%size;
            if(table[newindex]==key){
                table[newindex]=NULL;
                return;
            }
        }
        cout<< key<< "not found in the table"<<endl;
    }

    bool searchkey(int key){
       int u=hash1(key);
       int v=hash2(key);

        for(int i=0;i<size;i++){
           int newindex=(u+i*v)%size;
            if(table[newindex]==key){
                return true;
            }
        }
        cout<< key<< "not found in the table"<<endl;
        return false;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<< i << ":"<< table[i]<<endl;
        }
    }
};
