#include<iostream>
using namespace std;

void merge(int arr[],int strt,int mid,int end){

    int leftsize = mid-strt+1;
    int rightsize = end-mid;

    int leftarr[leftsize];
    int rightarr[rightsize];

    for(int i=0;i<leftsize;i++){
        leftarr[i]=arr[strt+i];
    }
    for(int i=0;i<rightsize;i++){
        rightarr[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=strt;

    while(i<leftsize && j<rightsize){
        if(leftarr[i]<=rightarr[j]){
            arr[k]=leftarr[i];
            i++;
        }
        else{
            arr[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while(i<leftsize){
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<rightsize){
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int strt,int end){
    if(strt<end){
        int mid=strt+(end-strt/2);
        
        mergesort(arr,strt,mid);
        mergesort(arr,mid+1,end);
        merge(arr,strt,mid,end);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    mergesort(arr, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}
