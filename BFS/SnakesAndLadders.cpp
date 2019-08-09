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
using namespace std;

#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << "      ";} cout << endl;}

pair<int, int> posnToCoord(int N, int posn) {
	int row;
	int col;
	if (posn <= N) {
		row = N-1;
	}
	else {
		if (posn % N == 0) {
			row = (N-1) - ((posn / N) - 1);
		}
		else {
			row = N-1-floor(posn / N);
		}
	}
	//if row is not divisible by 2, smallest number on left
	if (row % 2 != 0) {
		if (posn % N == 0) {
			col = N - 1;
		}
		else {
			col = (posn % N) - 1;
		}
	}
	else { // smallest number on right
		if (posn % N == 0) {
			col = 0;
		}
		else {
			col = N - (posn % N);
		}
	}
	return pair<int, int>(row, col);
}

struct State {
	int num;
	int numMoves;
	State(int n, int nm) {
		num = n; 
		numMoves = nm;
	}
};

//https://leetcode.com/problems/snakes-and-ladders/
//still need to test this out
int snakesAndLadders(vector<vector<int>>& board) {
	int N = board.size();
	State s1 = State(1, 0);
	queue<State> q;
	vector<bool> visited(N*N, 0);
	q.push(s1);
	while (!q.empty()) {
		State front = q.front();
		q.pop();
		visited[front.num] = 1;
		pair<int, int> c = posnToCoord(N, front.num);
		if (c.first == 0 && c.second == 0) return front.numMoves;
		for (int i = 1; i <= 6; ++i) {
			int nextPosn = front.num + i;
			c = posnToCoord(N, nextPosn);
			if (board[c.first][c.second] == -1) {
				if (visited[nextPosn] == false) {
					State s = State(front.num + i, front.numMoves + 1);
					q.push(s);
				}
			}
			else {
				if (visited[board[c.first][c.second]] == false) {
					State s = State(board[c.first][c.second], front.numMoves + 1);
					q.push(s);
				}
			}
		}

	}
	return -1;
}
