#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
 int partition(int arr[],int strt,int end){
    int pivot = arr[end];
    int idx = strt-1;

    for(int j=strt;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx],arr[j]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
 }
 void quicksort(int arr[],int strt,int end){

    if(strt<end){
        int pi=partition(arr,strt,end);

        quicksort(arr,strt,pi-1);
        quicksort(arr,pi+1,end);
    }
 }
 void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<< arr[i]<< " ";
    }
 }
 int main(){
    int arr[]={5,2,4,6,1,3};
    int size= sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    cout<< "sorted array: ";
    printarr(arr,size);
    return 0;
 }
