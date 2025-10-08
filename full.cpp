string permutation

#include <iostream>
#include <string>
using namespace std;



void permuteString(string &s, int l, int r) {
    if (l == r) {
        cout << s << endl;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);                  // Choose
        permuteString(s, l + 1, r);        // Explore
        swap(s[l], s[i]);                  // Un-choose (Backtrack)
    }
}

int main() {
    string str = "abc";
    cout << "Permutations of string \"" << str << "\":" << endl;
    permuteString(str, 0, str.length() - 1);
    return 0;
}

array permutation

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void permuteArray(int arr[], int l, int r) {
    if (l == r) {
        printArray(arr, r + 1);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(arr[l], arr[i]);              // Choose
        permuteArray(arr, l + 1, r);       // Explore
        swap(arr[l], arr[i]);              // Un-choose (Backtrack)
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Permutations of array:" << endl;
    permuteArray(arr, 0, n - 1);
    return 0;
}

palindrome partitioning

#include <iostream>
#include <string>
using namespace std;

const int N = 3;
const int MAX_LENGTH = 6;

char grid[N][N] = {
    {'a', 'b', 'a'},
    {'c', 'a', 'c'},
    {'d', 'b', 'd'}
};

bool visited[N][N];

// Function to check if a string is a palindrome
bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// Backtracking function to explore palindromes
void backtrack(int r, int c, string path) {
    if (path.length() > MAX_LENGTH) return;

    // If current path is a palindrome and at least length 2
    if (path.length() >= 2 && isPalindrome(path)) {
        cout << "Palindrome found: " << path << endl;
    }

    // Explore all directions
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; dir++) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc]) {
            visited[nr][nc] = true;
            backtrack(nr, nc, path + grid[nr][nc]);
            visited[nr][nc] = false; // backtrack
        }
    }
}

// Start backtracking from every cell
void findPalindromes() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string start(1, grid[i][j]);
            visited[i][j] = true;
            backtrack(i, j, start);
            visited[i][j] = false;
        }
    }
}

int main() {
    cout << "Palindromes found in grid:\n";
    findPalindromes();
    return 0;
}

row palindrome

#include <iostream>
#include <string>
using namespace std;

const int N = 3;

char grid[N][N] = {
    {'a', 'b', 'a'},
    {'c', 'a', 'j'},
    {'d', 'b', 'd'}
};

// Function to check if a string is a palindrome
bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// Function to find all palindromic substrings in each row
void findRowPalindromes() {
    cout << "Palindromes found in rows:\n";

    for (int row = 0; row < N; row++) {
        for (int start = 0; start < N; start++) {
            string path = "";
            for (int end = start; end < N; end++) {
                path += grid[row][end];  // Form substring
                if (path.length() >= 2 && isPalindrome(path)) {
                    cout << "Row " << row << ": " << path << endl;
                }
            }
        }
    }
}

int main() {
    findRowPalindromes();
    return 0;
}

cat & rabbit

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

rat in a maze

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

 nqueens

 class Solution {
public:
    bool issafe(vector<string> &board, int row, int col, int n) {
       
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void nqueen(vector<string> &board, vector<vector<string>>& ans, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (issafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueen(board, ans, row + 1, n);
                board[row][j] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueen(board, ans, 0, n);
        return ans;
    }
};

subset1

class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allSubsets){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allSubsets);
        ans.pop_back();
        getAllSubsets(nums,ans,i+1,allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums,ans,0,allSubsets);

        return allSubsets;
    }
};

subset2

class Solution {
public:

void getallsubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allsubsets){
    if(i==nums.size()){
        allsubsets.push_back({ans});
        return;
    }

    ans.push_back(nums[i]);
    getallsubsets(nums,ans,i+1,allsubsets);
    ans.pop_back();
    int idx=i+1;
    while(idx<nums.size()&&nums[idx]==nums[idx-1]){
        idx++;
    }
    getallsubsets(nums,ans,idx,allsubsets);

}
void bubbleSort(vector<int> &nums) {
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = 0; j < nums.size() - i - 1; j++) {
            if(nums[j] > nums[j+1]) {
             swap(nums[j], nums[j+1]);
            }
        }
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allsubsets;
        bubbleSort(nums);
        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};

