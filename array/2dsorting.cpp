#include <iostream>
using namespace std;

int main() {
    const int rows = 3, cols = 3;
    int arr[rows][cols] = {{9, 2, 7}, {4, 6, 1}, {8, 3, 5}};

    int total = rows * cols;

    // Bubble Sort across the entire matrix
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            // Map 1D index to 2D coordinates
            int r1 = j / cols, c1 = j % cols;
            int r2 = (j + 1) / cols, c2 = (j + 1) % cols;

            if (arr[r1][c1] > arr[r2][c2]) {
                int temp = arr[r1][c1];
                arr[r1][c1] = arr[r2][c2];
                arr[r2][c2] = temp;
            }
        }
    }

    // Print result
    cout << "Sorted 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
