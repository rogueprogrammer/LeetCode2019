#include "header.h"
    //https://leetcode.com/problems/is-graph-bipartite/
    // idea: find out whether can the graph be colored with 2 colors (no two colors adjacent) using BFS
    //passed all test cases
    bool isBipartite(vector<vector<int>>& graph) {
        
        //coloring is either(0-not colored, 1-red, 2-blue)
        vector<int> coloring(graph.size(), 0);
        
        //queue containing all the nodes in traversal so far
        queue<int> q;
        //needs to loop through all the courses, in case the graph is disconnected
        for(int i = 0; i < graph.size(); ++i){
            if(coloring[i] != 0) continue;
            q.push(i);
            int curColor = 1;
            coloring[i] = curColor;
            curColor = 2;
            while(!q.empty()){
                int top = q.front();
                int curColor = coloring[top];
                int neighColor = 0;
                if(curColor == 1) neighColor = 2;
                else if(curColor == 2) neighColor = 1;
                vector<int> neighbors = graph[top];
                for(int n : neighbors){
                    if(coloring[n] == 0){ //not yet colored
                        q.push(n);
                        //coloring[n] = curColor;
                        coloring[n] = neighColor;
                    }
                }
                q.pop();
            }
        }

        //check adjacent nodes are different colors
        for(int i = 0; i < graph.size(); ++i){
            int curNode = i;
            vector<int> neighbors = graph[curNode];
            int curColor = coloring[curNode];
            for(int n : neighbors){
                if(coloring[n] == curColor){
                    return false;
                } 
            }
        }
        return true;
    }
    
    int main() {
    
        vector<vector<int>> graph = {
            //{1,3},{0,2},{1,3},{0,2}  
            //{1}, {0}, {4}, {4}, {2, 3}
            {1, 4}, {0, 2}, {1}, {4}, {0, 3}
        };
        cout << isBipartite(graph) << endl;
    }
