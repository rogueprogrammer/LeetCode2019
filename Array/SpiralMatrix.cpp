// https://leetcode.com/problems/spiral-matrix/
/*
{1,2,3},
{4,5,6},
{7,8,9}
->{1,2,3,6,9,8,7,4,5,6}
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    vector<int> res;
    if (matrix.size() == 0) return res;
    int rowBegin = 0;
    int colBegin = 0;
    int rowEnd = matrix.size() - 1;
    int colEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
        // traverse right
        for (int i = colBegin; i <= colEnd; ++i) {
            res.push_back(matrix[rowBegin][i]);
        }
        // done with first row
        rowBegin++; 

        // traverse down
        for (int i = rowBegin; i <= rowEnd; ++i) {
            res.push_back(matrix[i][colEnd]);
        }
        // done with last col
        colEnd--; 

        // traverse left
        if (rowBegin <= rowEnd) {
            for (int i = colEnd; i >= colBegin; --i) {
                res.push_back(matrix[rowEnd][i]);
            }
            // done with last row
            rowEnd--; 
        }

        // traverse up
        if (colBegin <= colEnd) {

            for (int i = rowEnd; i >= rowBegin; --i) {
                res.push_back(matrix[i][colBegin]);
            }
            // done with first col
            colBegin++;
        }
    }
    return res;
}
