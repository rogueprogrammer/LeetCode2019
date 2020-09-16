// https://leetcode.com/problems/minimum-path-sum/submissions/
int minPathSum(vector<vector<int>>& grid) {
        
        /*       
        1, 3, 1
        1, 5, 1
        4, 2, 1
        let dp[i][j] = sum up to grid[i][j]
                     = grid[0][0] if i == j == 0
                     = min(left+cur, up+cur) = min(dp[i][j-1], dp[i-1][j])+grid[i][j]
        return dp[rows-1][col-1]
        
        */
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        for(int i = 0; i < rows; ++i){
            
            for(int j = 0; j < cols; ++j){
                if(i == j && i == 0){
                    dp[i][j] = grid[0][0];
                } else{
                    int up = -1;
                    int left = -1;
                    if(i != 0){ // get up
                        up = dp[i-1][j];
                    }
                    if(j != 0){ // get left
                        left = dp[i][j-1];
                    }
                    if(up == -1){
                        dp[i][j] = grid[i][j] + left;
                    } else if(left == -1){
                        dp[i][j] = grid[i][j] + up;
                    } else{ //both are not -1, since both cannot be -1
                        dp[i][j] = min(up, left) + grid[i][j];
                    }
                    
                }
                
            }
        }
        return dp[rows-1][cols-1];
        
    }
