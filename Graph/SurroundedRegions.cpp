#include "header.h"

//https://leetcode.com/problems/surrounded-regions/
//passed all test cases
class Solution {
public:
    
    //return true if not on border and if cell contains 'O'
    bool isValid(vector<vector<char>>& board, int row, int col){
        int numRows = board.size();
        int numCols = board[0].size();
        return (row > 0) && (row < numRows-1) && (col > 0) && (col < numCols - 1) && (board[row][col] == 'O');
    }
    
    void BFS(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        
        while(!q.empty()){
            pair<int, int> front = q.front();
            int cr = front.first;
            int cc = front.second;
            int up = cr - 1;
            int down = cr + 1;
            int left = cc - 1;
            int right = cc + 1;
            if(isValid(grid, up, cc)){
                grid[up][cc] = 'B';
                q.push(make_pair(up, cc));
            }
            if(isValid(grid, down, cc)){
                grid[down][cc] = 'B';
                q.push(make_pair(down, cc));
            }
            if(isValid(grid, cr, left)){
                grid[cr][left] = 'B';
                q.push(make_pair(cr, left));
            }
            if(isValid(grid, cr, right)){
                grid[cr][right] = 'B';
                q.push(make_pair(cr, right));
            }
            q.pop();
        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        /*
        Algorithm:
        1. traverse border and find all nodes that are 'O', Mark them as 'B' and do a BFS looking for any
        subsequent 'O', replacing them with 'B'.
        2. Traverse board again and any node that is 'B' mark as 'O'. Else if it is 'X' or 'O', mark it as 'X'
        */
        int numRows = board.size();
        if(numRows == 0) return;
        int numCols = board[0].size();
        if(numCols == 0) return;
        //traverse top and bottom border
        for(int col = 0; col < numCols; ++col ){
            if(board[0][col] == 'O'){
                board[0][col] = 'B';
                BFS(board, 0, col);
            }
            if(board[numRows-1][col] == 'O'){
                board[numRows-1][col] = 'B';
                BFS(board, numRows - 1, col);
            }
        }
        //traverse left and right border
        for(int row = 0; row < numRows; ++row){
            if(board[row][0] == 'O'){
                board[row][0] = 'B';
                BFS(board, row, 0);
            }
            if(board[row][numCols-1] == 'O'){
                board[row][numCols-1] = 'B';
                BFS(board, row, numCols-1);
            }
        }
        
        //Step 2. 
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j < numCols; ++j){
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                } else{
                    board[i][j] = 'X';
                }
            }
        } 
    }
};
