#include "header.h"
//https://leetcode.com/problems/search-in-rotated-sorted-array
//passed all test cases
//Idea is to find the pivot point (smallest element in array) first, and then do binary search in range[l, r], depdnding on 
// whether the target is between pivot and end or from 0 to pivot point -1.

class Solution {
public:
       
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        // Step 1 - find the pivot point (the smallest element in nums)
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            int mid = (lo + hi) /2;
            if(nums[mid] > nums[hi]){ // pivot point is on right side of mid
                lo = mid + 1;
            } else{ // pivot is on left side of mid
                hi = mid;
            }
        }
        int start = lo; //start is the index of the pivot point
        
        // Step 2 - now we must decide to search for target between pivot point and end of the array, or
        // between 0 and the pivot point
        if(target >= nums[start] && target<= nums[nums.size()-1]){
            lo = start;
            hi = nums.size()-1;
        } else if(start > 0 && target >= nums[0] && target <= nums[start-1]){
            lo = 0;
            hi = start - 1;
        }
        
        // Step 3 - now we do normal binary search from lo to hi searching for target
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                lo = mid+1;
            } else{ //nums[mid] > target
                hi= mid-1;
            }
        }
        return -1;
    }
};
