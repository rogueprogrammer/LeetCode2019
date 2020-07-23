#include "Header.h"
//https://leetcode.com/problems/word-search/submissions/

bool isSafe(vector<vector<char>>& board, int row, int col) {
    int numRows = board.size();
    int numCols = board[0].size();

    if ((row >= 0 && row < numRows) && (col >= 0 && col < numCols)) {
        return true;
    }
    return false;
}

void dfs(vector<vector<char>>& board, string word, int row, int col, int posn, bool& found) {

    if (posn == word.size()) {
        found = true;
        return;
    }

    char temp = board[row][col];
    board[row][col] = '0'; //mark node as visited so we don't visit it again

    //check up
    if (isSafe(board, row - 1, col)) {
        if (board[row - 1][col] == word[posn]) {
            dfs(board, word, row - 1, col, posn + 1, found);
        }

    }

    //check down
    if (isSafe(board, row + 1, col)) {
        if (board[row + 1][col] == word[posn]) {
            dfs(board, word, row + 1, col, posn + 1, found);
        }
    }

    //check left
    if (isSafe(board, row, col - 1)) {
        if (board[row][col - 1] == word[posn]) {
            dfs(board, word, row, col - 1, posn + 1, found);
        }
    }

    //check right
    if (isSafe(board, row, col + 1)) {
        if (board[row][col + 1] == word[posn]) {
            dfs(board, word, row, col + 1, posn + 1, found);
        }
    }

    board[row][col] = temp;
}

bool exist(vector<vector<char>>& board, string word) {
    if (word == "")return false;

    int numRows = board.size();
    int numCols = board[0].size();
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (board[i][j] == word[0]) {
                bool found = false;
                dfs(board, word, i, j, 1, found);
                if (found == true) return true;
            }
        }
    }
    return false;
}

void main() {
    /*vector<vector<char>> board = {
        {'C', 'A', 'A'} ,
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    string word = "AAB";*/
    vector<vector<char>> board = 
    {
        {'A', 'B', 'C', 'E'},
        { 'S', 'F', 'E', 'S' },
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCESEEEFS";


    cout << exist(board, word) << endl;
	  system("PAUSE");
}
