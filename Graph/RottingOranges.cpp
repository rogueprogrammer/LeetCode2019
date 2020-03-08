
//https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    
 int bfs(vector<vector<int>>& grid, int row, int col) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(row, col));
    int numMinutes = -1;
    int numRows = grid.size();
    int numCols = grid[0].size();

    while (!q.empty()) {
        pair<int, int> top = q.front(); int row = top.first; int col = top.second;
        q.pop();
        bool pushed = false;
        //up
        if (row > 0 && grid[row - 1][col] == 1) {
            q.push(pair<int, int>(row - 1, col));
            pushed = true;
            grid[row - 1][col] = 0;
        }

        //down
        if (row < numRows - 1 && grid[row + 1][col] == 1) {
            q.push(pair<int, int>(row + 1, col));
            pushed = true;
            grid[row + 1][col] = 0;
        }

        //left
        if (col > 0 && grid[row][col - 1] == 1) {
            q.push(pair<int, int>(row, col - 1));
            pushed = true;
            grid[row][col-1] = 0;
        }

        //right
        if (col < numCols - 1 && grid[row][col + 1] == 1) {
            q.push(pair<int, int>(row, col + 1));
            pushed = true;
            grid[row][col+1] = 0;
        }
        if (pushed) {
            ++numMinutes;
        }
    }
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    if(numMinutes == -1) return 0;
    return numMinutes;
}


int orangesRotting(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    if(grid.size() == 1 &&grid[0].size() == 1){
        if(grid[0][0] == 0){
            return 0;
        }
    }
    int numOranges = 0;
    bool foundRottingOrange = false;
    int row = -1; int col = -1;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (!foundRottingOrange && grid[i][j] == 2) {
                foundRottingOrange = true;
                row = i; col = j;
            }
        }
    }
    if (row == -1) { //coudn't find any rotting oranges
        return -1;
    }
    return bfs(grid, row, col);
}  
};
