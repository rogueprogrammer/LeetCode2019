
//https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
class Solution {
public:
  
  int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0;
        int hi = A.size()-1; 
        while(lo < hi){
            int mid = (lo+hi)/2;
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
                return mid;
            }
            else if(A[mid] > A[mid-1]){
                lo = mid;
            }
            else if(A[mid] > A[mid+1]){
                hi = mid;
            }
        }
        return -1;
    }

};
