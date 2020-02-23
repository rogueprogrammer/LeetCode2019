#include "Header.h"
//https://leetcode.com/problems/sliding-window-maximum
/* O(n) Algorithm:
      Monolythic Deque: A deque of indices with invariant that it is descending order based on                               nums[i].
                        Whenever you add an element to the dq, if the current element to add is                               greater than the front of the deque, then pop everything off the dq.
                        Pop off front of deque if index is < curIndex - k + 1
       0  1   2   3  4  5  6  7
      [1, 3, -1, -3, 5, 3, 6, 7]

      dq: 0(1) i = 0
          1(3) i = 1
          1(3), 2(-1) i = 2 -> res = 3
          1(3), 2(-1), 3(-3) i = 3 -> res = 3, 3
          pop off 1 at i = 4 since 4-1+1 > k
          4(5) i = 4 -> res = 3, 3, 5
          ...
      */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; //double-ended queue
    vector<int> res;
    /*
    0  1   2   3  4  5  6  7
    [1, 3, -1, -3, 5, 3, 6, 7] */
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            dq.push_back(i); //dq: 0
            continue;
        }
        while (!dq.empty() && dq.front() < nums[i] - k + 1) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.front()] < nums[i]) {
            dq.pop_front();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

void main() {
    
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> res = maxSlidingWindow(nums, 3);
    DEBUG_1D(res);
	cout << "leet time" << endl;
	system("PAUSE");
}
