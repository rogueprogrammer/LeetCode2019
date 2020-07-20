//https://leetcode.com/problems/design-tic-tac-toe/
//O(1) time, O(N) space for move function. Maintain row/col arrays for both p1 and p2, as well as diag and antidiag variables for both players.
class TicTacToe {
public:
    
    int N;
    vector<int> rowsP1;
    vector<int> rowsP2;
    vector<int> colsP1;
    vector<int> colsP2;

    int diagP1;
    int diagP2;
    int antiDiagP1;
    int antiDiagP2;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        diagP1 = 0; diagP2 = 0;
        antiDiagP1 = 0; antiDiagP2 = 0;
        for(int i = 0; i < n; ++i){
            rowsP1.push_back(0);
            rowsP2.push_back(0);
            colsP1.push_back(0);
            colsP2.push_back(0);
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
           
           if(player == 1){
                rowsP1[row]++;
                colsP1[col]++;
                if(row == col){
                    diagP1++;
                }
                if(row + col == N-1){
                    antiDiagP1++;
                }
                if(rowsP1[row] == N || colsP1[col] == N || diagP1 == N || antiDiagP1 == N){
                    return 1;
                }
               
           } else{
               rowsP2[row]++;
               colsP2[col]++;
                if(row == col){
                    diagP2++;
                }
                if(row + col == N-1){
                    antiDiagP2++;
                }
               if(rowsP2[row] == N || colsP2[col] == N || diagP2 == N || antiDiagP2 == N){
                   return 2;
               }
           }
           return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
