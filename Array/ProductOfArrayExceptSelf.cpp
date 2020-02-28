
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


//Optimization, can do it with O(1) extra space:

vector<int> productExceptSelfOptimized(vector<int>& nums) {
	/*
	Initialize res array with products left of element i. Start at very right, and continuously update right product and 
	updating the res array based on right * left:
	nums:  [1           2          3        4]
	res:   [24           12           8        6]
	right:  24            24            12        4
	*/
	vector<int> res(nums.size());
	if (nums.size() == 0) return res;
	for (int i = 0; i < nums.size(); ++i) {
		//populate left
		if (i == 0) {
			res[i] = 1;
		}
		else {
			res[i] = res[i - 1] * nums[i - 1];
		}
	}
	int right = nums[nums.size() - 1];
	for (int i = nums.size() - 2; i >= 0; --i) {
		res[i] *= right;
		right = right * nums[i];
	}
	return res;
}
