#include <iostream>
#include <string>
using namespace std;

const int N = 5;
const int MAX_PATHS = 100;

int jungle[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

string rabbitPaths[MAX_PATHS];
int rabbitVisited[MAX_PATHS][N][N];
int rabbitPathCount = 0;

string catPaths[MAX_PATHS];
int catVisited[MAX_PATHS][N][N];
int catPathCount = 0;

void findAllPaths(int matrix[N][N], int vis[N][N], string ans[MAX_PATHS], int visitedStore[MAX_PATHS][N][N],
                  int &pathCount, int n, int r, int c, int destR, int destC, string path) {
    if (r < 0 || c < 0 || r >= n || c >= n || matrix[r][c] == 0 || vis[r][c] == 1)
        return;

    if (r == destR && c == destC) {
        vis[r][c] = 1;
        ans[pathCount] = path;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visitedStore[pathCount][i][j] = vis[i][j];
        pathCount++;
        vis[r][c] = 0;
        return;
    }

    vis[r][c] = 1;
    findAllPaths(matrix, vis, ans, visitedStore, pathCount, n, r + 1, c, destR, destC, path + "d");
    findAllPaths(matrix, vis, ans, visitedStore, pathCount, n, r - 1, c, destR, destC, path + "u");
    findAllPaths(matrix, vis, ans, visitedStore, pathCount, n, r, c + 1, destR, destC, path + "r");
    findAllPaths(matrix, vis, ans, visitedStore, pathCount, n, r, c - 1, destR, destC, path + "l");
    vis[r][c] = 0;
}

void printPaths(string label, string ans[MAX_PATHS], int visitedStore[MAX_PATHS][N][N], int pathCount) {
    for (int p = 0; p < pathCount; p++) {
        cout << label << " Path " << p + 1 << ": " << ans[p] << endl;
        cout << "Visited Matrix:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << visitedStore[p][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void showIntersections() {
    cout << "Intersection Points in Common Paths :\n";
    for (int rp = 0; rp < rabbitPathCount; rp++) {
        for (int cp = 0; cp < catPathCount; cp++) {
            cout << "Intersection of Rabbit Path " << rp + 1 << " and Cat Path " << cp + 1 << ": ";
            bool found = false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (rabbitVisited[rp][i][j] == 1 && catVisited[cp][i][j] == 1) {
                        cout << "(" << i << "," << j << ") ";
                        found = true;
                    }
                }
            }
            if (!found)
                cout << "No Intersection";
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int vis[N][N] = {0};

    
    findAllPaths(jungle, vis, rabbitPaths, rabbitVisited, rabbitPathCount, N, 0, 0, 2, 2, "");

  
    findAllPaths(jungle, vis, catPaths, catVisited, catPathCount, N, 4, 4, 2, 2, "");

    
    cout << "========= Rabbit Paths =========\n";
    printPaths("Rabbit", rabbitPaths, rabbitVisited, rabbitPathCount);

    cout << "========= Cat Paths =========\n";
    printPaths("Cat", catPaths, catVisited, catPathCount);

   
    showIntersections();

    return 0;
}
