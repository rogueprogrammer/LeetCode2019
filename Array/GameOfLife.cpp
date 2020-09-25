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
#include <List>
#include <assert.h>
using namespace std;
// https://leetcode.com/problems/game-of-life/
/*
    O(mn) runtime O(1) space solution: 
    

    if(cell is alive){
        -> if number of alive neighbors == 2 or 3 -> stay alive
        -> else dead
    }
    if(cell is dead){
        -> if cell has 3 alive neighbors -> becomes alive
    }
    Doing simple brute force with creating new board is simple but inefficient solution , as it requires O(mn) extra space.
    The below algorithm does this in place, with O(1) extra space:
    
    For example, consider input board:
    [0,1,0],
    [0,0,1],
    [1,1,1],
    [0,0,0]
    Create 2 more states, -1 and 2.
    -1 means dead now but once alive
    2 means alive now but once dead
    [0,-1,0],
    [2,0,1],
    [-1,1,1],
    [0,2,0]
    -> convert
    [0,0,0],
    [1,0,1],
    [0,1,1],
    [0,1,0]
    Algo:
    1. Go through the matrix, if cell is alive (1) and has 2 or 3 neighbors with value 1 or -1
        -> set to 1
       else set to -1.
       If cell is dead (0) and has 3 neighbors that are 1 or -1, -> set to 2
       else if cell is -1 or 2, it was already visited.
    2. Convert cells with value 2 -> 1, and cells with value -1 -> 0
    */



bool isAlive(vector<vector<int>> board, int i, int j) {
    int numRows = board.size(); int numCols = board[0].size();
    if (i >= 0 && i < numRows && j >= 0 && j < numCols && (board[i][j] == 1 || board[i][j] == -1)) {
        return true;
    }
    return false;
}

int GetNumAliveNeighbors(vector<vector<int>> board, int i, int j) {
    int numRows = board.size(); int numCols = board[0].size();
    int numAliveNeighbors = 0;
    int numDeadNeighbors = 0;
    if (isAlive(board, i-1, j)) {
        ++numAliveNeighbors;
    } //up
    
    if (isAlive(board, i, j - 1)) {
        ++numAliveNeighbors;
    } //left
    
    if (isAlive(board, i, j + 1)) {
        ++numAliveNeighbors;
    } //right
    
    if (isAlive(board, i+1, j)) {
        ++numAliveNeighbors;
    } //down  
    
    if (isAlive(board, i - 1, j - 1)) {
        ++numAliveNeighbors;
    } //up left
    
    if (isAlive(board, i - 1, j + 1)) {
        ++numAliveNeighbors;
    } //up right
   
    if (isAlive(board, i + 1, j - 1)) {
        ++numAliveNeighbors;
    }  //down left                           
    
    if (isAlive(board, i + 1, j + 1)) {
        ++numAliveNeighbors;
    } //get down right diag
    return numAliveNeighbors;

}


void gameOfLife(vector<vector<int>>& board) {
    
    int numRows = board.size();
    int numCols = board[0].size();

    // step 1
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            int numAlive = GetNumAliveNeighbors(board, i, j);
            
            if (board[i][j] == 1) {
                if (!(numAlive == 2 || numAlive == 3)) {
                    board[i][j] = -1;
                }
            }
            else if(board[i][j] == 0) {
                if (numAlive == 3) {
                    board[i][j] = 2;
                }
            }
        }
    }

    // step 2
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            }
            else if (board[i][j] == -1) {
                board[i][j] = 0;
            }

        }
    }

}


void main() {
    
    vector<vector<int>> board = {
        {0,1,0} ,
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    gameOfLife(board);


    system("PAUSE");
}
