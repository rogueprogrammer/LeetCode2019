// https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0){
            return false;
        }
        int cols = matrix[0].size();
        
        int lo = 0;
        int hi = (rows*cols)-1;
        
        while(lo <= hi){
            int mid = (lo+hi) / 2; 
            int r = mid / cols; 
            int c = mid % cols; 
            if(matrix[r][c] == target){
                return true;
            }
            if(target > matrix[r][c]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
            
        }
        return false;
        
    }
