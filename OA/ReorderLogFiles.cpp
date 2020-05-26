//https://leetcode.com/problems/reorder-log-files/

/*
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
O(NlogN) solution:
        1. Split logs into letter-logs and digit logs
	2. Sort all letter logs. If tie, then sort based on identifier (first word).
	3. Concatenate letter logs and digit logs.
*/

vector<string> reorderLogFiles(vector<string>& logs) {
	vector<pair<string, string>> letterLogs; //<first word, rest of log>
	vector<string> digitLogs; //need to maintain order of digit logs
	vector<string> res;

    for (string s : logs) {
        int i = 0;
		int lastSpace = 0;
		while (s[i] != ' ') { i++; lastSpace = i; }
		if (isalpha(s[++i])) {
			letterLogs.push_back(make_pair(s.substr(0, lastSpace), s.substr(i, s.size() - i +1)));
		}
		else {
			digitLogs.push_back(s);
		}
    }
	sort(letterLogs.begin(), letterLogs.end(),
		[](pair<string, string> a, pair<string, string>b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second;
		}
	);

	for (pair<string, string> s : letterLogs) {
		string log = s.first + " " + s.second;
		res.push_back(log);
	}

	for (string s : digitLogs) {
		res.push_back(s);
	}
	return res;
}
