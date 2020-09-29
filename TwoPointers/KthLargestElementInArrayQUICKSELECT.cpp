class Solution {
public:
    
    /* https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
    
    O(N) ALGORITHM TO GET Kth LARGEST ELEMENT IN ARRAY.
    Heap solution and sorting the array are obvious, and are O(nlogk) and O(nlogn) respectively, but
    O(N) is the best solution to get, which is what the below code implements:
    
    watched combination of https://www.youtube.com/watch?v=hGK_5n81drs and                  
    https://www.youtube.com/watch?v=MZaf_9IZCrc to understand quicksort/quickselect algo
    
    BEST WAY TO REMEMBER/RECALL THIS ALGO FROM MEMORY IS, 
    THE INVARIANT IS: ALL ELEMENTS LEFT OF PIVOT ARE LESS THAN PIVOT, ALL ELEMENTS RIGHT OF PIVOT ARE GREATER THAN PIVOT. 
    Thus we swap the fast pointer (j) with slow pointer i, each time we encounter elements less than pivot. Else we increment fast pointer j. 
    Pointer i is always the left boundary representing all the elements less than pivot. 
    
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
    
    int quickSelect(vector<int>& nums, int start, int end, int k){
        int i = start;
        int j = start;
        int n = nums.size();
        while(j < end){
            if(nums[j] > nums[end]){
                ++j;
            } else{
                swap(nums[i++], nums[j++]);
            }
        }
        swap(nums[i], nums[end]); //note that the last elem (at index end) is pivot point
        if(i == k){
            return nums[i];
        } else if(k > i){
            return quickSelect(nums, i+1, end, k);
        } else{ //k < i
            return quickSelect(nums, 0, i-1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, nums.size()-1, n-k);
    }
};
