//https://leetcode.com/problems/sentence-similarity-ii/
//passed 45/117 test cases
//general algo is right, but it fails on long test cases
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
	if (words1.size() != words2.size()) return false;

	//Build a graph out of pairs
	map<string, set<string>> adj;
	for (vector<string> pair : pairs){
		string p1 = pair[0];
		string p2 = pair[1];
		adj[p1].insert(p2);
		adj[p2].insert(p1);
	}

	//Do a BFS on each entry in hash table
	for (auto it = adj.begin(); it != adj.end(); ++it){
		string curWord = it->first;
		queue<string> q;
		set<string> visited;
		q.push(curWord);
		while (!q.empty()){
			string front = q.front();
			visited.insert(front);
			set<string> neighbors = adj[front];
			for (string n : neighbors){
				auto it = visited.find(n);
				if (it == visited.end()){
					adj[front].insert(n);
					adj[n].insert(front);
					adj[curWord].insert(n);
					adj[n].insert(curWord);
                    adj[curWord].insert(front);
					adj[front].insert(curWord);
					q.push(n);
				}
			}
			q.pop();
		}
	}
	//search similarities in the now complete graph
	for (int i = 0; i < words1.size(); ++i){
		string w1 = words1[i];
		string w2 = words2[i];
		set<string> neighbors = adj[w1]; //optimization - make neighbors a set in adj
		bool flagged = false;
		for (string n : neighbors){
			if (n == w2){
				flagged = true;
				break;
			}
		}
		if (!flagged) return false;
	}
	return true;
}
};
