//https://leetcode.com/problems/house-robber
class Solution {
public:
    /*
    1  3  1  3  100
    1  3  3  6  103
    */
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
         return 0;   
        } if(nums.size() == 1){
            return nums[0];
        } if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        // dp[i] represents the maximum we can steal upto house i
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];  
    }
};
