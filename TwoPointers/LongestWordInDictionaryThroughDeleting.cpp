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

//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
//submitted, passed all cases

//returns true if str1 is a subsequence of str2
bool isSubsequence(string str1, string str2) {
	int m = str1.size(); int n = str2.size();
	if (m > n) return false;
	int j = 0;
	for (int i = 0; i < n && j < m; ++i) {
		if (str1[j] == str2[i]) {
			++j;
		}
	}
	return j == m;
}


string findLongestWord(string s, vector<string>& d) {

	string res = "";
	for (string str : d) {
		if (isSubsequence(str, s) ) {
			if (str.size() > res.size()) {
				res = str;
			}
			else if (str.size() == res.size() && str < res) {
				res = str;
			}
		}
	}
	return res;
}
