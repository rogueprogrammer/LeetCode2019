// https://leetcode.com/problems/top-k-frequent-words/
//   a node can be (word, numTimes)
//   create a min heap of size k
// O(nlogk) algorithm
struct minHeapComparator {
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
		//if the words have same frequency, then sort the words with the one that comes lexographically first
		if (a.second == b.second) {
			return a.first < b.first;
		}
		else {
			return a.second > b.second;
		}
	}
};

vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string> res;
	unordered_map<string, int> ht;

	priority_queue<pair<string, int>, vector<pair<string, int>>, minHeapComparator	> pq;
	for (string curWord : words) {
		ht[curWord]++;
	}
	for (auto it : ht) {
		string curWord = it.first;
		int numOccurences = ht[curWord];

		pq.push(make_pair(curWord, numOccurences));
		if (pq.size() > k) {
			pq.pop();
		}
	}
	while (!pq.empty()) {
		string cur = pq.top().first;
		res.push_back(cur);
		pq.pop();
	}
	//res contains order of min heap, but needs to be reversed, since we want highest frequencies first
	reverse(res.begin(), res.end());

	return res;
}

void main() {
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	topKFrequent(words, 2);
	system("PAUSE");
}
