
/*
https://leetcode.com/problems/product-of-array-except-self/submissions/
Keep left array and right array. Left array contains product of all nums left of ith element. Right array
contains product of all nums right of ith element.
Thus the product at element i is the product of left[i]*right[i].
       [ 1   2   3   4]
Left:  [ 1   1   2   6]
Right: [ 24  12  4   1]
*/
vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> res;
	if (nums.size() == 0) return res;
	vector<int> left(nums.size());
	vector<int> right(nums.size());
	//populate left:
	left[0] = 1;
	for (int i = 1; i < left.size(); ++i) {
		left[i] = left[i - 1] * nums[i - 1];
	}
	//populate right:
	right[right.size() - 1] = 1;
	for (int i = right.size() - 2; i >= 0; --i) {
		right[i] = right[i - 1] * nums[i - 1];
	}

	for (int i = 0; i < nums.size(); ++i) {
		res.push_back(left[i] * right[i]);
	}
	return res;
}
