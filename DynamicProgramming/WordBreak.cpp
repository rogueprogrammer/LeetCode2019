//https://leetcode.com/problems/word-break
//passed all test cases
//Algorithm:
//let dp[i] == true if s[0, ..., i] can be formed by the dictionary
// for each i:
//     for each j = 0, ..., i
//           if dp[j]==true and s[j, ..., i] is in the dictionary, this means that s[0, ..., i] can be created by dictionary
//                 dp[i] is true

class Solution {
public:
 bool wordBreak(string s, vector<string>& wordDict) {
	if (s == "") return true;
	set<string> _set;
	for (string d : wordDict) {
		_set.insert(d);
	}

	vector<bool> dp(s.size());
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0) {
			string sub = ""; sub += s[i];
			dp[i] = _set.find(sub) != _set.end();
		}
		else {
			bool res = false;
			for (int j = 0; j < i; ++j) {
				string rest = s.substr(j + 1, i - j);
				auto it = _set.find(rest);
				res = res || (dp[j] && it != _set.end());
			}
			string sub = s.substr(0, i+1);
			auto it = _set.find(sub);
			dp[i] = res || it != _set.end();
		}
	}
	return dp[s.size() - 1];
}
};
