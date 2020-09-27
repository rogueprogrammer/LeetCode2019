class Solution {
public:
        /*  https://leetcode.com/problems/sliding-window-maximum/submissions/
       O(n) solution had to refer to the solution from here - https://www.youtube.com/watch?v=Szyj6BY9iSA
        - Invariant: DQ is in decreasing order. Anytime incoming element is more than the back, we don't care about the back element and keep popping it off. 
        Anytime incoming element is more than the front, we pop off the front. 
        
        - Why DQ? -> Need to push/pop elements to both front and back to maintain ordering
        - Why do we maintain DQ of indices instead of DQ of the array elements?
             -> We must maintain indices in dq because we need to know when the 
             front of dq index is out of range. We can then refer to nums[dq.front()] to get the elem
        */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq; //double-ended queue
        vector<int> res;
                
        for(int i = 0 ; i < nums.size(); ++i){
            int newComer = nums[i];
            
            while(!dq.empty() && newComer >= nums[dq.back()]){
                dq.pop_back();
            }
            while(!dq.empty() && newComer > nums[dq.front()]){
                dq.pop_front();
            }
            
            // if the front index of the dq is equal to i - k, it is officially out of range
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }
            
            dq.push_back(i);

            if(i >= k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};
