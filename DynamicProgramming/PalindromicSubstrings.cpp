#include "header.h"
//https://leetcode.com/problems/palindromic-substrings/submissions/
class Solution {
public:
   int countSubstrings(string s) {
	int numSubstrings = 0;
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			dp[i][j] = 0;
		}
	}

	int len = 0; int endStrReached = 0;
	while (endStrReached <= s.size()) {
		for (int row = 0; row < s.size(); ++row) {
			int col = row + len;
			if (col >= s.size()) { 
				break; 
			}
			if (len == 0) {
				dp[row][col] = 1;
			}
			else if (len == 1) {
				dp[row][col] = (s[row] == s[col]);
			}
			else {
				dp[row][col] = (s[row] == s[col]) && (dp[row + 1][col - 1]);
			}
			if (dp[row][col] == 1) {
				numSubstrings++;
			}
			if (col == s.size() - 1) {
				endStrReached++;
			}
		}
		++len;
		if (endStrReached == s.size()) break;
	}
	return numSubstrings;
}

    
};
