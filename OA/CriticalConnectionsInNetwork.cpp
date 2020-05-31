#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
using namespace std;

// https://leetcode.com/problems/critical-connections-in-a-network/
// passed 8/12 cases, due to using brute force algorithm which fails on large test cases with 1000+ nodes

/*
Brute force algorithm: First get count for number of critical connections. For each edge, remove it and see if number of connected components 
has increased. if this is the case, then critical component was found.  O(V*(V+E)) run-time
*/


int countComponents(int n, vector<vector<int>>& edges) {

    //build graph
    map<int, vector<int>> adj;
    for (vector<int> edge : edges) {
        int n1 = edge[0];
        int n2 = edge[1];
        if (n1 < 0 || n2 < 0) {
            continue;
        }
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> visited(n, 0);
    int numComponents = 0;
    int numVisited = 0;
    while (numVisited != n) {
        //find next node from visited that is not visited
        int nextNode;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                nextNode = i;
                break;
            }
        }
        ++numComponents;
        //Do a BFS on this node, marking each node thats visited
        queue<int> q;
        q.push(nextNode);
        visited[nextNode] = 1;
        ++numVisited;
        while (!q.empty()) {
            int topNode = q.front();
            vector<int> neighbors = adj[topNode];
            for (int n : neighbors) {
                if (visited[n] == 0) {
                    q.push(n);
                    visited[n] = 1;
                    ++numVisited;
                }
            }
            q.pop();
        }

    }
    return numComponents;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    int numComponenets = countComponents(n, connections);
    vector<vector<int>> criticalConnections;
    for (int i = 0; i < connections.size(); ++i) {
        int n1 = connections[i][0];
        int n2 = connections[i][1];

        connections[i][0] = -1;
        connections[i][1] = -1;
        int newNumComponents = countComponents(n, connections);
        if (newNumComponents != numComponenets) {
            vector<int> p;
            p.push_back(n1); p.push_back(n2);
            criticalConnections.push_back(p);
        }
        connections[i][0] = n1;
        connections[i][1] = n2;
    }
    return criticalConnections;
}

void main() {
    ///vector<vector<int>> edges = { {0, 1} ,{1, 2},{2, 0},{1, 3} };
    //criticalConnections(4, edges);
	
    vector<vector<int>> edges = { {0, 1}, { 0, 2 }, { 1, 3 }, { 2, 3 }, { 2, 5 }, { 5, 6 }, { 3, 4 }};
    criticalConnections(7, edges);
    system("PAUSE");
}
