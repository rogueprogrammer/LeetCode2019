#include "Header.h"

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//not working, but general algo should work. get back to this later

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int prev, int maxLen) {

    if (row < 0 || row > matrix.size() - 1 || col < 0 || col > matrix[0].size() - 1) {
        return maxLen;
    }

    if (prev > matrix[row][col]) {
        return maxLen;
    }

    int upMaxLen = dfs(matrix, dp, row - 1, col, matrix[row][col], maxLen + 1);
    int downMaxLen = dfs(matrix, dp, row + 1, col, matrix[row][col], maxLen + 1);
    int rightMaxLen = dfs(matrix, dp, row, col + 1, matrix[row][col], maxLen + 1);
    int leftMaxLen = dfs(matrix, dp, row, col - 1, matrix[row][col], maxLen + 1);

    dp[row][col] = max(max(upMaxLen, downMaxLen), max(rightMaxLen, leftMaxLen));
    return dp[row][col];
}


int longestIncreasingPath(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();
    if (rows == 0) {
        return 0;
    }

    //let dp[i][j] = length of longest increasing path up to matrix[i][j]
    vector<vector<int>> dp(rows, vector<int>(cols));
    int res = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dp[i][j] == 0) {
                int curLen = 1;
                dfs(matrix, dp, i, j, INT_MIN, curLen);
                res = max(res, curLen);
            }
        }
    }
    return res;
}

void main() {
    
    vector<vector<int>> m = {
        {2, 4, 5},
        {10, 3, 8},
        {20, 19, 30}
    };
    queue<int> q;
    q.front();

    cout << longestIncreasingPath(m) << endl;
    system("PAUSE");
}
