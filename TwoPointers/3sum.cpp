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

//https://leetcode.com/problems/3sum/
//submitted - passed all test cases
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) { return res; }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-2){
            
            int l = i + 1;
            int r = nums.size()-1;
            while(l < r){
                int target = -nums[i];
                if(nums[l] + nums[r] > target){
                    --r;
                }
                else if (nums[l] + nums[r] < target){
                    ++l;
                }
                else{
                    vector<int> t;
                    t.push_back(nums[l]);
                    t.push_back(nums[r]);
                    t.push_back(nums[i]);
                    sort(t.begin(), t.end());
                    res.push_back(t);
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1]) ++l;
	            while (r - 1 >= 0 && nums[r] == nums[r - 1]) --r;
                    --r;
                    ++l;
                }
                
            }
            ++i;
            while (i < nums.size() - 2 && (i - 1 >= 0) && (nums[i] == nums[i - 1])) ++i;
        }
        return res;      
        
    }
    
  void main(){  
      //vector<int> a = {-8, -6, -5, -2, 0, 1, 2, 3, 6, 7, 8, 9, 11};
      //vector<int> a = { 0, 0, 0 };
      vector<int> a = { -2, 0, 0, 2, 2 };
      vector<vector<int>> res = threeSum(a);
      DEBUG_2D(res);
  }
