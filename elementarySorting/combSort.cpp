
void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13; // shrink gap
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
