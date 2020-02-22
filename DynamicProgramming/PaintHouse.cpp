//https://leetcode.com/problems/paint-house/
class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
		vector<vector<int>> dp(costs.size(), vector<int>(3));
        for(int i = 0; i < costs.size(); ++i){
            for(int j = 0; j < 3; ++j){
            if(i == 0){
                dp[i][j] = costs[i][j];
            } else{
                int k, l;
                if(j == 0){
                     k = dp[i-1][1];
                     l = dp[i-1][2];
                } else if(j == 1){
                     k = dp[i-1][0];
                     l = dp[i-1][2];
                    
                } else{
                     k = dp[i-1][0];
                     l = dp[i-1][1];
                }
                dp[i][j] = costs[i][j] + min(k, l);   
            }
            }
            
        }
        int lastHouse = costs.size() -1;
        return min(min(dp[lastHouse][0], dp[lastHouse][1]), dp[lastHouse][2]);
     
	}


};
