vector<int> parent;

// https://leetcode.com/discuss/interview-question/356981
/*
Given an undirected graph with n nodes labeled 1..n. Some of the nodes are already connected. The i-th edge connects nodes edges[i][0] and edges[i][1] together. Your task is to augment this set of edges with additional edges to connect all the nodes. Find the minimum cost to add new edges between the nodes such that all the nodes are accessible from each other.

Input:

n, an int representing the total number of nodes.
edges, a list of integer pair representing the nodes already connected by an edge.
newEdges, a list where each element is a triplet representing the pair of nodes between which an edge can be added and the cost of addition, respectively (e.g. [1, 2, 5] means to add an edge between node 1 and 2, the cost would be 5).
Example 1:

Input: n = 6, edges = [[1, 4], [4, 5], [2, 3]], newEdges = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]
Output: 7
Explanation:
There are 3 connected components [1, 4, 5], [2, 3] and [6].
We can connect these components into a single component by connecting node 1 to node 2 and node 1 to node 6 at a minimum cost of 5 + 2 = 7.
*/

int find(int node){
    if (parent[node] == node) {
        return node;
    }
    else {
        return find(parent[node]);
    }
}

int minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& newEdges) {
    vector<vector<int>> connections;
    for (vector<int> edge : edges) {
        edge.push_back(0);
        connections.push_back(edge);
    }
    for (vector<int> newEdge : newEdges) {
        connections.push_back(newEdge);
    }

    sort(connections.begin(), connections.end(), [](vector<int> a, vector<int> b) {
        return a[2] < b[2];
        }
    );
    for (int i = 0; i <= N; ++i) {
        parent.push_back(i);
    }
    int res = 0;
    int count = 1;
    for (vector<int> c : connections) {
        int c1 = c[0];
        int c2 = c[1];
        int cost = c[2];
        int p1 = find(c1); //find the highest parent of c1
        int p2 = find(c2); //find the highest parent of c2
        if (p1 != p2) { //union
            parent[c2] = p1;
            res += cost;
            ++count;
        }
        if (count == N) {
            return res;
        }
    }

    return -1;
}


void main() {

    vector<vector<int>> edges = { {1, 4} ,{4, 5},{2, 3} };
    vector<vector<int>> newEdges = { {1, 2, 5} , {1, 3, 10}, {1, 6, 2}, {5, 6, 5} };
    int res = minimumCost(6, edges, newEdges);
    system("PAUSE");
}
