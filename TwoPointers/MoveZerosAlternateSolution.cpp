class Solution {
public:
    
    /*
        https://leetcode.com/problems/move-zeroes/
                                                       placeNonZeros
        [1,               3,                12,             3,           12]
                                                                         i
        
        
        output: [1, 3, 12, 0, 0]
        
                                                     placeNonZeros
        [1,               2,                3,             3,           0]
                                                                        i
         Place all Non zero elements at the front of the list as soon as you encounter a non-zero
         element at index i. Increment placeNonZeros pointer forward.
        */
    
    void moveZeroes(vector<int>& nums) {
        
        int placeNonZeros = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                nums[placeNonZeros++] = nums[i];
            }
        }
        
        for(int i = placeNonZeros; i < nums.size(); ++i){
            nums[i] = 0;
        }
        
    }
};
