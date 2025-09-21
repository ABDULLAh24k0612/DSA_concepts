#include <iostream>
using namespace std;

// Binary search function
// Returns the index of target if found, else returns -1
int binarySearch(int arr[], int n, int target) {
    int left = 0;         // Start of the search range
    int right = n - 1;    // End of the search range

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find the middle element to avoid overflow

        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Target is in the right half
        }
        else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target not found
}


