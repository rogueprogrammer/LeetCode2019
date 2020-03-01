#include "Header.h"
//https://leetcode.com/problems/clone-graph/
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> ht;

void dfsCopyIntoHashTable(Node* node) {
    auto it = ht.find(node);
    if (it == ht.end())
    {
        Node* n = new Node(node->val);
        ht[node] = n;
    }
    else {
        return;
    }
    for (int i = 0; i < node->neighbors.size(); ++i) {
        dfsCopyIntoHashTable(node->neighbors[i]);
    }
}
set<Node*> visited;
void dfsCopyNeighbors(Node* node) {
    auto it = visited.find(node);
    if (it != visited.end()) {
        return;
    }
    visited.insert(node);
    Node* cur = ht[node];
    for (int i = 0; i < node->neighbors.size(); ++i) {
        Node* neighbor_i = node->neighbors[i];
        Node* cur_neighbor_i = ht[neighbor_i];
        cur->neighbors.push_back(cur_neighbor_i);
        dfsCopyNeighbors(neighbor_i);
    }
}

Node* cloneGraph(Node* node) {
    /*
    Do a DFS, clone the current node, add it to hash table, then iterate on all the neighbors
    of current node.
    */

    if (!node) return NULL;
    dfsCopyIntoHashTable(node);
    dfsCopyNeighbors(node);
    return ht[node];
}

void main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->neighbors.push_back(b); a->neighbors.push_back(d);
    b->neighbors.push_back(a); b->neighbors.push_back(c);
    c->neighbors.push_back(b); c->neighbors.push_back(d);
    d->neighbors.push_back(a); d->neighbors.push_back(c);
    cloneGraph(a);
}
