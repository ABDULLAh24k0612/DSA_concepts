#include <iostream>
using namespace std;

//----------------------------------------------
// Merge two sorted halves of the array
//----------------------------------------------
void mergeArrays(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;   // Size of left half
    int n2 = right - mid;      // Size of right half

    // Temporary arrays
    int leftArr[n1];
    int rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0;      // index for leftArr
    int j = 0;      // index for rightArr
    int k = left;   // index for original array

    // Merge the two sorted halves
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } 
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

//----------------------------------------------
// Recursive Merge Sort
//----------------------------------------------
void mergeSort(int arr[], int left, int right) {

    // Base condition: stop when left >= right
    if (left < right) {

        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        mergeArrays(arr, left, mid, right);
    }
}

//----------------------------------------------
// Utility function to print array
//----------------------------------------------
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//----------------------------------------------
// MAIN FUNCTION
//----------------------------------------------
int main() {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}
