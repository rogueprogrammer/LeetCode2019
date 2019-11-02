
//passed 86/117 cases
/*
Failed case:
Input:
["zy","zx"]
Output:
"yx"
Expected:
"yxz"
*/
//https://leetcode.com/problems/alien-dictionary
class Solution {
public:

 //given two words, find the first pair of characters that are not equal in w1 and w2
//ex: "wrt", "wrf" -> t,f
//if no such pair exists, return NULL
pair<char, char> getOrderingFrom2Words(string w1, string w2){
	int len = min(w1.size(), w2.size());
	for (int i = 0; i < len; ++i){
		char c1 = w1[i];
		char c2 = w2[i];
		if (c1 != c2){
			return make_pair(c1, c2);
		}
	}
	return make_pair(' ', ' ');
}

string alienOrder(vector<string>& words) {
	string topologicalSortedOrdering = "";
    
	//Step 1 - build graph
	set<char> allChars; //to get size of graph
	map<char, set<char>> adj; //char -> all chars that come after it
	for (int i = 0; i < words.size(); ++i){
		string cur = words[i];
		for (int j = i + 1; j < words.size(); ++j){
			string next = words[j];
			pair<char, char> ord = getOrderingFrom2Words(cur, next);
			if (ord.first == ' ' && ord.second == ' '){
				continue;
			}
			char first = ord.first; char second = ord.second;
			adj[first].insert(second);
			allChars.insert(first); allChars.insert(second);
		}
	}
	int numNodes = allChars.size();
    if(numNodes <= 1){
	    for(string w : words){
            for(char c : w){
                allChars.insert(c);
            }
        }
        for(char c : allChars){
            topologicalSortedOrdering += c;
        }
        return topologicalSortedOrdering;
    }

	//Step 2 - Detect cycle (by computing indegrees) and build up the topological sorted ordering
	map<char, int> indegrees;
	for (auto it = adj.begin(); it != adj.end(); ++it){
		char ch = it->first;
		set<char> neighbors = it->second;
		auto it2 = indegrees.find(ch);
		if (it2 == indegrees.end()){
			indegrees[ch] = 0;
		}
		for (char n : neighbors){
			auto it2 = indegrees.find(n);
			if (it2 == indegrees.end()){
				indegrees[n] = 1;
			}
			else{
				indegrees[n]++;
			}
		}
	}
	// find all nodes with indegree== 0 and push onto q
	queue<char> q;
	for (auto it = indegrees.begin(); it != indegrees.end(); ++it){
		if (it->second == 0){
			q.push(it->first);
		}
	}

	int count = q.size();

	while (!q.empty()){
		char ch = q.front();
		set<char> neighbors = adj[ch];
		for (char n : neighbors){
			if (--indegrees[n] == 0){
				q.push(n);
				++count;
			}
		}
		topologicalSortedOrdering += ch;
		q.pop();
	}
	if (count == numNodes){
		return topologicalSortedOrdering;
	}
	return "";
}

};
