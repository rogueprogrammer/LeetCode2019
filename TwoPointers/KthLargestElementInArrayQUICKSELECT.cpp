class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        https://leetcode.com/problems/kth-largest-element-in-an-array/
        orig array: [4, 2, 1, 5, 6, 3]
        
        
        
                                 pivot
        [2,   1,   3,   5,   6,   4]
                   i                               
                                   j
                           
                           pivot
        [4      6         5]                  
         i
                           j
        
        
                 pivot
        [ 5      6]
        i
                 j
                                   
        if(nums[j] > pivot) ->advance j
        if(nums[j] < pivot) -> swap(nums[j], nums[i]) i++; j++
        once all iterations are done, swap (nums[i], nums[pivot])
        if(i == n-k), then we're done, return nums[i]
        else if(n-k > i) -> recurse on right side of i(i+1, ..., n)
        else if(n-k < i) -> recurse on left side of i (0, ..., i-1)
        */
    }
};
