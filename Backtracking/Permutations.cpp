/* 
* https://leetcode.com/problems/permutations/submissions/
idea is to use backtracking algo, where we build a temp vector from scratch, and
whenever we want to add a number into temp, we first search if it already exists in it. if not, then we add it to temp, call backtrack recursively again, 
and after the call to backtrack, we just pop off the number we added to temp.

example:
let nums = [1,2,3], the following is recursion tree on temp variable:

                                   {}
                            {1}                 {2}                       {3}
                        {1, 2}  {1, 3}         {2, 1}      {2, 3}       {3, 1}     {3, 2} 
                     {1, 2, 3}  {1, 3, 2}      {2, 1, 3}  {2, 3, 1}    {3, 1, 2}   {3, 2, 1}

runtime = space = O(n*n!)
*/


void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {

    if (temp.size() == nums.size()) {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (find(temp.begin(), temp.end(), nums[i]) == temp.end()) { // if we haven't already used this number:
            temp.push_back(nums[i]);
            backtrack(nums, temp, result);
            temp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(nums, temp, result);
    return result;
}




void main() {
    vector<int> nums = { 1, 2, 3 };
    permute(nums);

    system("PAUSE");
}
