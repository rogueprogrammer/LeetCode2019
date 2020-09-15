class Solution {
public:
     /*
       
        
        [-1, 0, 1, 2, -1, -4]
        O(n^3) trivial solution - pair each num with another num and store sum in ht. It would be O(n^2) on average case but the reason why its O(n^3) is because if all the pairs have the same sum, then they all
        hash to the same value.
        
        O(n^2) if you sort the array and use two pointers
        [-4, -1, -1, 0, 1, 2]
                  i  l  r   
              
        (-1, -1, 2), (-1, 0, 1), (-1, 0, 1)
        
        
        [-2, 0, 0, 2, 2]
         i      l  r
         
         (-2, 0, 2)
         
         
        */
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
                    res.push_back(t);
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1]) l++;
	            while (r - 1 >= 0 && nums[r] == nums[r - 1]) r--;
                    --r;
                    ++l;
                }
                
            }
            ++i;
            while (i < nums.size() - 2 && (i - 1 >= 0) && (nums[i] == nums[i - 1])){++i;}
        }
        return res;      
        
    }
};
