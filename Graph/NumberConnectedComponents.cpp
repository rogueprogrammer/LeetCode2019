#include "header.h"

// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
//passed all test cases
/*
Idea: generate a graph, and do a BFS on each unvisited node, incrementing the count each time you're done a BFS and want to find 
another unvisited node to perform BFS on. 
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        //build graph
        map<int, vector<int>> adj;
        for(vector<int> edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        
        vector<int> visited(n, 0);
        int numComponents = 0;
        int numVisited = 0;
        while(numVisited != n){
            //find next node from visited that is not visited
            int nextNode;
            for(int i = 0; i < n; ++i){
                if(visited[i] == 0){
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
            while(!q.empty()){
                int topNode = q.front();
                vector<int> neighbors = adj[topNode];
                for(int n : neighbors){
                    if(visited[n] == 0){
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
};
