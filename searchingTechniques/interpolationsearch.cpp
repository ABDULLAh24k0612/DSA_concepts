#include <iostream>
using namespace std;

// Interpolation search function
// Returns index of target if found, else -1
int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // To avoid division by zero if arr[high] == arr[low]
        if (arr[high] == arr[low]) {
            if (arr[low] == target) return low;
            else return -1;
        }

        // Estimate the position of the target based on distribution
        int pos = low + ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Check if target is found
        if (arr[pos] == target) {
            return pos;
        }

        // If target is larger, target is in upper part
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // If target is smaller, target is in lower part
        else {
            high = pos - 1;
        }
    }

    return -1; // Target not found
}


