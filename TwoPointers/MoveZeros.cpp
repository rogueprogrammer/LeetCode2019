//https://leetcode.com/problems/move-zeroes/submissions/
class Solution {
public:
    /*
    Count number of zeros so far and keep swapping non-zero elements with that number of zeros away
    10 9 0 8 7 0 6 5 0 3 1
    10 9 8 7 6 5 3 1 0 0 0
     Runtime: 12 ms, faster than 96.77% of C++ online submissions for Move Zeroes.
    Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Move Zeroes.
    */
    void moveZeroes(vector<int>& nums) {
        int numZeros = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                ++numZeros;
            } else{
                int j = i - numZeros;
                swap(nums[i], nums[j]);
            }
        }
    }
};
