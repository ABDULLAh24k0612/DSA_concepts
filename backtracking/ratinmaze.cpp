#include<iostream>
#include<string>
using namespace std;

const int N = 10; 
int finalVis[N][N]; 

void helper(int matrix[N][N], int vis[N][N], int n, int r, int c, string path, string ans[], int &count) {
    if (r < 0 || c < 0 || r >= n || c >= n || matrix[r][c] == 0 || vis[r][c] == 1)
        return;

    if (r == n - 1 && c == n - 1) {
        ans[count++] = path;

        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                finalVis[i][j] = vis[i][j];
        finalVis[r][c] = 1; 
        return;
    }

    vis[r][c] = 1;

    helper(matrix, vis, n, r + 1, c, path + "d", ans, count);
    helper(matrix, vis, n, r - 1, c, path + "u", ans, count);
    helper(matrix, vis, n, r, c + 1, path + "r", ans, count);
    helper(matrix, vis, n, r, c - 1, path + "l", ans, count);

    vis[r][c] = 0;
}

void findPath(int matrix[N][N], int n) {
    string ans[100]; 
    int vis[N][N] = {0}; 
    int count = 0;

    helper(matrix, vis, n, 0, 0, "", ans, count);

    cout << "Paths:\n";
    for (int i = 0; i < count; i++) {
        cout << ans[i] << endl;
    }

    if (count > 0) {
        cout << "\nVisited Matrix for one successful path:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << finalVis[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nNo path found.\n";
    }
}

int main() {
    int matrix[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = 4;
    findPath(matrix, n);

    return 0;
}
