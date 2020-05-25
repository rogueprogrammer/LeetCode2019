
//https://leetcode.com/problems/rotting-oranges/
/*
   0 - empty, 1 - fresh, 1 - rotten

   min=0
   0    1    2
   1    1    1
   2    1    0

   min=1
   0    2    2
   1    1    2
   2    2    0

   min=2
   0    2    2
   2    2    2
   2    2    0
Find all rotten oranges add them to queue, do BFS to find each adjacent orange that is not rotten, then make it rotten, add it to queue,
and continue BFS until no more oranges. Since the contamination happens layer by layer, a BFS like traversal can find the shortest 
amount of time until all oranges are contaminated. Runtime = O(N), since we first iterate through entire grid, then we run BFS on the
grid, which would be at most N oranges added.
   */

int orangesRotting(vector<vector<int>>& grid) {
	int minutes = 0;
	queue<pair<int, int>> rottenOranges;
	int numRows = grid.size();
	int numCols = grid[0].size();
	int numRottenOranges = 0;
	int numCleanOranges = 0;
	//collect all rotten oranges
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			if (grid[i][j] == 2) {
				rottenOranges.push(make_pair(i, j));
				numRottenOranges++;
			}
			else if (grid[i][j] == 1) {
				numCleanOranges++;
			}
		}
	}
	rottenOranges.push(make_pair(-1, -1)); //end of timer
	int totalOranges = numRottenOranges + numCleanOranges;

	int turnedRotten = 0;
	while (!rottenOranges.empty()) {
		pair<int, int> front = rottenOranges.front();
		rottenOranges.pop();
		if (front.first == -1) {
			if (rottenOranges.empty()) {
				break;
			}
			else {
				++minutes;
				rottenOranges.push(make_pair(-1, -1));
				continue;
			}
		}
		else {
			int row = front.first; int col = front.second;
			//check up
			if (row - 1 >= 0 && grid[row - 1][col] == 1) {
				grid[row - 1][col] = 2;
				rottenOranges.push(make_pair(row - 1, col));
				++turnedRotten;
			}
			//check left
			if (col - 1 >= 0 && grid[row][col - 1] == 1) {
				grid[row][col - 1] = 2;
				rottenOranges.push(make_pair(row, col - 1));
				++turnedRotten;
			}
			//check right
			if (col + 1 < numCols && grid[row][col + 1] == 1) {
				grid[row][col + 1] = 2;
				rottenOranges.push(make_pair(row, col + 1));
				++turnedRotten;
			}
			//check down
			if (row + 1 < numRows && grid[row + 1][col] == 1) {
				grid[row + 1][col] = 2;
				rottenOranges.push(make_pair(row + 1, col));
				++turnedRotten;
			}
		}
	}
	if (numCleanOranges == turnedRotten) {
		return minutes;
	}
	return -1;
}
