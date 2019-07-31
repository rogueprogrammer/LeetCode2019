#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;

//https://leetcode.com/problems/circular-array-loop/
bool circularArrayLoop(vector<int>& nums) {

	for (int i = 0; i < nums.size(); ++i) {

		if (nums[i] == 0) {
			//find next element that is not 0. if all elements are 0, return false
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[j] != 0) i = j;
			}
			for (int j = i - 1; j >= 0; --j) {
				if (nums[j] != 0) i = j;
			}
			return false;
		}

		int cyclelen = 0;
		int next = i;
		cout << next << " ";
		while (1) {
			int prev = next;
			next = getIndex(next, nums);
			if (prev == next) break;
			++cyclelen;
			if (nums[prev] * nums[next] < 0) break;
			cout << next << " ";
			if (next == i && cyclelen > 1) {
				return true;
			}
			if (nums[next] == 0) break;
			nums[prev] = 0;
			
		}
		cout << endl;
		nums[i] = 0;

	}
	return false;
}


void main() {

	//vector<int> nums = { 2, -1, 1, 2, 2 }; //true
	//vector<int> nums = { 3, 1, 2, 2, 2, -1, 1, 1 }; //false
	//vector<int> nums = { -1, 2 };
	//vector<int> nums = { 3, 1, 2 };
	
	vector<int> nums = { 1, 1, 2 };
	cout << "RESULT IS: " << circularArrayLoop(nums) << endl;

	system("PAUSE");
}
