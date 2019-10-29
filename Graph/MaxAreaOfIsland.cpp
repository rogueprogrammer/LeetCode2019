#include "header.h"

//https://leetcode.com/problems/max-area-of-island/
    struct point{
      int row;
      int col;
      point(int r, int c) {
          row = r;
          col = c;
      }
    };
    
    bool isSafe(vector<vector<int>>& grid, int row, int col){
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1) return true;
        return false;
    }
    
    int BFS(vector<vector<int>>& grid, int r, int c){
        queue<point> q;
        point p(r, c);
        q.push(p);
        int area = 0;
        while(!q.empty()){
            point top = q.front();
            int row = top.row;
            int col = top.col;
            if(grid[row][col] == 0) {
                q.pop();
                continue;
            }
            
            grid[row][col] = 0; //mark the land node as visited
            
            if(isSafe(grid, row-1, col)){
                q.push(point(row-1, col));
            }
            if(isSafe(grid, row+1, col)){
                q.push(point(row+1, col));
            }
            if(isSafe(grid, row, col-1)){
                q.push(point(row, col-1));
            }
            if(isSafe(grid, row, col+1)){
                q.push(point(row, col+1));
            }
            if(!q.empty()){
              q.pop();
              ++area;
            }
        }
        return area;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == 1){
                    int size = BFS(grid,r,c);
                    cout << "SIZE: " << size << endl;
                    maxSize = max(size, maxSize);
                }
            }
        }
        return maxSize;
    }

int main() {
    
    /*vector<vector<int>> grid = 
    {{1,1,0,0,0},
     {1,1,0,0,0},
     {0,0,0,1,1},
     {0,0,0,1,1}
    };*/
    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,1}
    };
    
    maxAreaOfIsland(grid);

}

