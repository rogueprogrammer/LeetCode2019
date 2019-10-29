#include "header.h"

//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    struct point{
      int row;
      int col;
      point(int r, int c) {
          row = r;
          col = c;
      }
    };
    
    bool isSafe(vector<vector<char>>& grid, int row, int col){
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == '1') return true;
        return false;
    }
    
    void BFS(vector<vector<char>>& grid, int r, int c){
        queue<point> q;
        point p(r, c);
        q.push(p);
        while(!q.empty()){
            point top = q.front();
            int row = top.row;
            int col = top.col;
            grid[row][col] = '0'; //mark the land node as visited
            if(isSafe(grid, row-1, col)) q.push(point(row-1, col));
            if(isSafe(grid, row+1, col)) q.push(point(row+1, col));
            if(isSafe(grid, row, col-1)) q.push(point(row, col-1));
            if(isSafe(grid, row, col+1)) q.push(point(row, col+1));
            q.pop();
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == '1'){
                    BFS(grid,r,c);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};
