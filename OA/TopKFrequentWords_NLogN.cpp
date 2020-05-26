//https://leetcode.com/problems/top-k-frequent-words/submissions/
//O(nlogn) solution, sort the hashtable and return k most frequent
vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string> res;
	unordered_map<string, int> ht;
	for (string w : words) {
		ht[w]++;
	}
	vector<pair<string, int>> pre;
	for (auto it = ht.begin(); it != ht.end(); it++) {
		pre.push_back(make_pair(it->first, it->second));
	}
	sort(pre.begin(), pre.end(), [](pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second) {
			return a < b;
			} 
		return a.second > b.second;
		});
	for (pair<string, int> p : pre) {
		if (res.size() >= k) {
			break;
		}
		res.push_back(p.first);
	}
	return res;
}
