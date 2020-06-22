#include "Header.h"

// https://leetcode.com/problems/connecting-cities-with-minimum-cost/submissions/
// 51/63
// Using Kruskal's union find algorithm for finding the minimum spanning tree of the graph

vector<int> parent;

int find(int node){
    if (parent[node] == node) {
        return node;
    }
    else {
        return find(parent[node]);
    }
}


int minimumCost(int N, vector<vector<int>>& connections) {

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
            /*
             N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
            Output: 6
            step 1 - sort: [ [2,3,1], [1,2,5], [1,3,6] ]
            parent: [1 : 1, 2 : 2, 3 : 3]
            parent: [1 : 1, 2 : 2, 3 : 2]
            parent: [1 : 1, 2 : 1, 3 : 2]
            */
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

    vector<vector<int>> connections = { {1, 2, 5},{1, 3, 6},{2, 3, 1} };
    int res = minimumCost(3, connections);
    system("PAUSE");
}
