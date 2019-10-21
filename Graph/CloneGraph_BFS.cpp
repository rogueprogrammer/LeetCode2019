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

unordered_map<int, Node*> visited;
Node* cloneGraph(Node* node) {
	if (!node) return NULL;
	queue<Node*> q;
	q.push(node);
	Node* root;
	int i = 0;
	while (!q.empty()) {
		Node* top = q.front();
		visited[top->val] = top;
		Node* newNode = new Node();
		if (i == 0) root = newNode;
		newNode->val = top->val;
		for (int i = 0; i < top->neighbors.size(); ++i) {
			newNode->neighbors.push_back(top->neighbors[i]);
			auto it = visited.find(top->neighbors[i]->val);
			if (it == visited.end()) {
				q.push(top->neighbors[i]);
			}
		}
		q.pop();
		++i;
	}
	return root;
}

void main() {
	Node n1 = Node();
	Node n2 = Node();
	Node n3 = Node();
	Node n4 = Node();
	n1.val = 1; n2.val = 2; n3.val = 3; n4.val = 4;
	n1.neighbors.push_back(&n2); n1.neighbors.push_back(&n4);
	n2.neighbors.push_back(&n1); n2.neighbors.push_back(&n3);
	n3.neighbors.push_back(&n2); n3.neighbors.push_back(&n4);
	n4.neighbors.push_back(&n1); n4.neighbors.push_back(&n3);
	Node* res = cloneGraph(&n1);
}
