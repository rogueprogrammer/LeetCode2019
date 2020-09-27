/*

We have n databases in an array a, where a[i] is the file size limit of that database. 
We want to put a image in a database but we also want to copy the image over to the next k-1 databases adjacent to this one. 
Therefore the file size is limited by the k databases we choose. Find the maximum file size we can put. Example:

	arr = [1, 6, 3, 2, 1] and k = 3
	Our options are: [1,6,3], [6,3,2], [3,2,1].
	Each of these options can store files of size at most 1, 2, 1 respectively because min([1,6,3]), min([6,3,2]), and min([3,2,1]) = 1, 2, 1 respectively.
	Therefore, the maximum file we can store in this array of databases is 2 because max(1, 2, 1) = 2.


*/


int minSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq; //double-ended queue
    int result = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        int newComer = nums[i];

        while (!dq.empty() && newComer <= nums[dq.back()]) {
            dq.pop_back();
        }
        while (!dq.empty() && newComer < nums[dq.front()]) {
            dq.pop_front();
        }

        // if the front index of the dq is equal to i - k, it is officially out of range
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result = max(result, nums[dq.front()]);
        }
    }

    return result;

}
