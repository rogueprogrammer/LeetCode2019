/*
 Given two arrays:

1) arr1 of size n, which contains n positive integers sorted in the ascending order.

2) arr2 of size (2*n) (twice the size of first), which contains n positive integers sorted in the ascending order in its first half. Second half of this array arr2 is empty. (Empty elements are marked by 0).

Write a function that takes these two arrays, and merges the first one into second one, resulting in an increasingly sorted array of (2*n) positive integers. 
Example

Input:

n = 3

arr1 = [1 3 5]

arr2 = [2 4 6 0 0 0]



Output: arr2 = [1 2 3 4 5 6]
 */
void merger_first_into_second(vector<int>& arr1, 
vector<int>& arr2) {
    
    /*
    Start iterating pointer at end of second array, which has the first available spot, and keep taking the max of the
    pointers pointing to arr1[i] and arr2[j], decreasing i and j each time.
    O(n) algorithm
    i           
    1      3        5
    2      2        3        4       5      6
    j                            
           cur
    
    */
    
    
    int n = arr1.size()-1;
    int i = n; int j = n; int cur = arr2.size()-1;
    
    while(cur >= 0){
        int curMax;
        if(i < 0){
            curMax = arr2[j];
        }
        else if(j < 0){
            curMax = arr1[i];
        } else{
            curMax = max(arr1[i], arr2[j]);    
        }
        
        arr2[cur] = curMax;
        
        if(curMax == arr1[i]){
            --i;
        } else {
            --j;
        }
        --cur;
    }
    
}

