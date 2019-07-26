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

//https://leetcode.com/problems/trapping-rain-water
int trap(vector<int>& height) {
	if (height.size() == 0) return 0;
	int water = 0;
	vector<int> lefts;
	vector<int> rights;

	for (int i = 0; i < height.size(); ++i) {
		int l = i - 1;
		while (l > 0) {
			if (l - 1 > 0 && height[l - 1] > height[l]) {
				--l;
			}
			else {
				l = height[l];
				break;
			}
		}
		int r = i + 1;
		while (r < height.size()) {
			if (r + 1 < height.size() && height[r + 1] > height[r]) {
				++r;
			}
			else {
				r = height[r];
				break;
			}
		}
		lefts.push_back(l); rights.push_back(r);
	}
	for (int i = 0; i < height.size()-1; ++i) {
		int amount = min(lefts[i], rights[i]) - height[i];
		if (amount > 0) {
			water += amount;
		}
	}
	return water;
}
