#include <iostream>
using namespace std;



void radixSort(int arr[], int n) {

    
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {

        cout << "\nSorting by digit place = " << exp << endl;

        int output[n];      
        int count[10] = {0}; 

        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10; 
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;

            output[count[digit] - 1] = arr[i];
            count[digit]--; 
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "\nSorted array: ";
    printArray(arr, n);

    return 0;
}
