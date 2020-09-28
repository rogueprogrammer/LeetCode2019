// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m; //indices
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        auto it = m.find(target - nums[i]);
        if(it != m.end()){
            res.push_back(i);
            res.push_back(it->second);
        }else{
            m[nums[i]] = i;
        }

    }
    
    return res;
}
};
