int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        // Check if current element matches the target
        if (arr[i] == target) {
            return i;  // Found the target, return its index
        }
    }
    return -1;  // Target not found in the array
}
