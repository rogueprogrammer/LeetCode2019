class Solution {
public:
    //https://leetcode.com/problems/search-a-2d-matrix-ii/
    /*20
    [1, 4, 7, 11,15]
    [2, 5, 8, 12,19]
    [3, 6, 9, 16,22]
    [10,13,14,17,24]
    [18,21,23,26,30]
    O(m+n) solution. Start at top right and compare if its bigger than target, then it has to be in a column left of it.
    If its smaller, then it must be in a row below it.
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
         if(numRows == 0){
            return false;
        }
        int numCols = matrix[0].size();
       
        int row = 0; int col = numCols-1;
        while(row <= numRows-1 && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            
        }
        return false;
    }
};
