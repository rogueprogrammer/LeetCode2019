

//https://leetcode.com/problems/minimum-window-substring/
//passed 267/268 cases. last test case gives TLE on very long test case
bool isSatisfied(string& cur, string& t, unordered_map<char, int> m) {
	int len_unique_chars = m.size();
	//check if all chars of cur have all chars of t
	if (t.size() > cur.size()) return false;
	int counter = 0;
	for (int i = 0; i < cur.size(); ++i) {
		m[cur[i]]--;
		if (m[cur[i]] == 0) {
			++counter;
		}
		//if (--m[cur[i]] == 0) ++counter;
	}
	return counter == len_unique_chars;
}


//use two pointers/sliding window technique, L and R, and expand window if the current window is not satisfying
//contract window if current window meets requirements. keep contracting until it no longer satisfies. 
string minWindow(string s, string t) {
	int L = 0; int R = 0;
	string best = s;
	unordered_map<char, int> m;
	for (int i = 0; i < t.size(); ++i) m[t[i]]++;
	while (L <= R && R <= s.size()) {
		string cur = s.substr(L, R - L + 1);
		if (isSatisfied(cur, t, m)) {
			if (cur.size() < best.size()) best = cur;
			++L;
		}
		else {
			++R;
		}
	}
	if (best == s) {
		if (isSatisfied(best, t, m)) return best;
		else return "";
	}
	return best;
}
