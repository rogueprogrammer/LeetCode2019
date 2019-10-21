#include "header.h"

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

//https://leetcode.com/problems/clone-graph/
//seems to work on my machine, but LC OJ has a problem with it
unordered_set<int> visited;
Node* cloneGraph(Node* node) {
	Node* new_node = new Node(node->val, node->neighbors);
	visited.insert(new_node->val);
	for (int i = 0; i < node->neighbors.size(); ++i) {
		auto it = visited.find(node->neighbors[i]->val);
		if (it == visited.end()) {
			cloneGraph(node->neighbors[i]);
		}
	}
	return new_node;
}
