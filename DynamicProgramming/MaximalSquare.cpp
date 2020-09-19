// https://leetcode.com/problems/maximal-square/submissions/
/*
        [
            ["1","1","1","1","0"],
            ["1","1","1","1","0"],
            ["1","1","1","1","1"],
            ["1","1","1","1","1],
            ["0","0","1","1","1"]
        ]
        
        [
            ["1","0","1","0"],
            ["1","0","1","1"],
            ["1","0","1","1"],
            ["1","1","1","1"]
        ]
        let dp[i][j] = minimal square size upto matrix[i][j]
        Strategy: Take the minimum of the val that is up, left and diag of current value. 
        The current square's dimension will be one more than the min of these three values. The reason why we take min, is because one of these three may have a smaller
        square size. thus we are taking the minimal square so far and incrementing one size larger to it. 
        int minLen = min(up, left, diag)
        dp[i][j] = pow([sqrt(minLen)+1], 2)

       */
int maximalSquare(vector<vector<char>>& matrix) {
    
    int numRows = matrix.size(); 
    if(numRows == 0){
        return 0;
    }
    int numCols = matrix[0].size();
    
    vector<vector<int>> dp(numRows, vector<int>(numCols));
    int largestSize = matrix[0][0]-'0';
    for (int i = 0; i < numRows; ++i) {

        for (int j = 0; j < numCols; ++j) {

            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j] - '0';
            }
            else {
                if (matrix[i][j] == '1') {
                    int up = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    int diag = dp[i-1][j-1];
                    int m = min(min(left, up), diag);
                    dp[i][j] = pow(sqrt(m) + 1, 2);
                }
                else {
                    dp[i][j] = 0;
                }
            }
            largestSize = max(largestSize, dp[i][j]);
        }
    }
    return largestSize;
}
