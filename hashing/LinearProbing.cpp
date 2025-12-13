#include<iostream>
using namespace std;

class linearProbing{
    public:

    int size;
    int *table;
    
    linearProbing(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        } 
    }
    
    int hash(int key){
        return key%size;
    }
    void insert(int key){
        int index=hash(key);
        
        for(int i=0;i<size;i++){
            int newindex=(index+i)%size;
            if(table[newindex]==NULL){
                table[newindex]=key;
                break;
            }
        }
    }
    
    void deletekey(int key){
        int index=hash(key);

        for(int i=0;i<size;i++){
            int newindex=(index+i)%size;
            if(table[newindex]==key){
                table[newindex]=NULL;
                return;
            }
        }
        cout<< key<< "not found in the table"<<endl;
    }

    bool searchkey(int key){
        int index=hash(key);

        for(int i=0;i<size;i++){
            int newindex=(index+i)%size;
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
