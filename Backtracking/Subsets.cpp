//https://leetcode.com/problems/subsets

class Solution {
public:
    /* nums = [1,2,3]
     res =[] , [1], [1,2], [1,2,3],[1,3], [2], [2,3], [3]
     Runtime Complexity - O(2^n)
     Space Complexity - O(n)
    */
    
    void generateAllSubsets(vector<vector<int>>& allSubsets, vector<int> nums, vector<int>& cur, int index){    
        allSubsets.push_back(cur);
        for(int i = index; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            generateAllSubsets(allSubsets, nums, cur, i+1);
            cur.pop_back();
        }    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> cur;
        generateAllSubsets(allSubsets, nums, cur, 0);
        return allSubsets;        
    }
};
