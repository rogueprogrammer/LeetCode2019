//https://leetcode.com/problems/coin-change/submissions/

int coinChange(vector<int>& coins, int amount) {
        /*
        coins=[1, 2, 5], amount = 11
        let dp[i] = min number of coins to make i cents
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        dp[11] = min(dp[11], dp[11 - 5]+1)
               = min(dp[11], dp[6]+1)
        dp[6] = min(dp[6-1]+ 1, dp[6-2]+1, dp[6-5]+1)
              = min(dp[5]+1, dp[4]+1, dp[1]+1)
        
        dp[5] = min(dp[5-1]+1, dp[5-2]+1, dp[5-5]+1)
              = min(dp[4]+1, dp[3]+1, dp[0]+1)
        
        dp[4] = min(dp[4-1]+1, dp[4-2]+1) = min(dp[3]+1, dp[2]+1) = min(2+1, 1+1) = 2
        
        dp[3] = min(dp[3-1]+1, dp[3-2]+1)
              = min(dp[2]+1, dp[1]+1) = min(1+1, 1+1) = 2
        dp[2] = 1
        dp[1] = 1
        dp[0] = 0
        
        [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11]
        [ 0, ]
        
        
        */
        vector<int> dp(amount+1, INT_MAX);
        for(int i = 0; i <= amount; ++i){
            if(i == 0){
                dp[0] = 0;
            } else{
                for(int j = 0; j < coins.size(); ++j){
                    int coinAmount = coins[j];
                    if(coinAmount > i) continue;
                    if(dp[i-coinAmount] == INT_MAX) continue;
                    dp[i] = min(dp[i], dp[i-coinAmount] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount]; 
    }
