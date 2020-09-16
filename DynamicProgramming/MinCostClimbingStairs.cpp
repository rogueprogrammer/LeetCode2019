 //https://leetcode.com/problems/min-cost-climbing-stairs/
 int minCostClimbingStairs(vector<int>& cost) {
        /*
        [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
        let dp[i] = min cost to get to step i
                  = min(dp[i-1], dp[i-2])+cost[i]
        [1, 100, 2, 3, 3, 103, 4, 5, 104, 6]
        */
        if(cost.size() == 0) return 0;
        if(cost.size() == 1) return cost[0];
        if(cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < dp.size(); ++i){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
