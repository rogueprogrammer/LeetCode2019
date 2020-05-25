
//https://leetcode.com/problems/rotting-oranges/

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
