#include "header.h"
//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
   void dfs(vector<vector<char>>& grid, int x, int y) {
	
	if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
		return;
	}
	if (grid[x][y] == '0') {
		return;
	}
	grid[x][y] = '0'; //mark it as visited

	dfs(grid, x - 1, y);
	dfs(grid, x + 1, y);
	dfs(grid, x, y - 1);
	dfs(grid, x, y + 1);
}

int numIslands(vector<vector<char>>& grid) {
	int numIslands = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == '1') {
				dfs(grid, i, j);
				++numIslands;
			}
		}
	}
	return numIslands;
}
};
