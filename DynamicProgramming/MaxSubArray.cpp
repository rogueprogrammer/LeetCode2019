 
 // https://leetcode.com/problems/maximum-subarray/submissions/
 int maxSubArray(vector<int>& nums) {
        /*
        5:25
        [-2, 1, -3, 4, -1, 2, 1, -5, 4]
     dp: [-2, -1, -3, 4, 3, 5, 6, 1, 5]  
        maxSubArraySum = 6
        let dp[i] = maxSum upto and including A[i]
                  = max(A[i], maxSoFar+A[i])
        maxSubArraySum = max of all dp[i].
        */
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int maxSoFar = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            res = max(res, maxSoFar);
        }
        return res;
    }
