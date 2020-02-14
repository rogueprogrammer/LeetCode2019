
//https://leetcode.com/problems/24-game/
//64/70 test cases passed
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        int posn = 0;
        vector<vector<int>> numPerms;
        allPermutationsOfNums(numPerms, nums, posn);
        bool res = false;
        for(vector<int> n : numPerms){
            res = isValid(n);
            if(res) return true;
        }
        return false;
    }
       
    void allPermutationsOfNums(vector<vector<int>>& perms, 
                                     vector<int>& nums, int& posn){
        if(posn >= nums.size()){
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            swap(nums[i], nums[posn]);
            perms.push_back(nums);
            ++posn;
            allPermutationsOfNums(perms, nums, posn);
            --posn;
            swap(nums[i], nums[posn]); //backtrack
        }
    }
    
    /*
    4,1,8,7 ->
    [a&b, c, d], [a&c, b, d], [a&d, b, c], [a, b&c, d], [a, b&d, c], [a, b, c&d]
    each & would be substituted with {+, -, *, /}
    */
    bool isValid(vector<int>& nums){
        int a = nums[0]; int b = nums[1]; int c = nums[2]; int d = nums[3];
        if (isValid(a+b, c, d)    ||     isValid(a-b, c, d)      || isValid(a*b, c, d)     || isValid(a/b, c, d)) return true;
        
        if (isValid(a+c, b, d) || isValid(a-c, b, d) || isValid(a*c, b, d) || isValid(a/c, b, d)) return true;
        
        if ( isValid(a+d, b, c) || isValid(a-d, b, c) || isValid(a*d, b, c) || isValid(a/d, b, c)) return true;
        
        if( isValid(a, b+c, d) || isValid(a, b-c, d) || isValid(a, b*c, d) ||  isValid(a, b/c, d) ) return true;
        
        if(  isValid(a, b+d, c) || isValid(a, b-d, c) || isValid(a, b*d, c) || isValid(a, b/d, c) ) return true;
        
        if(  isValid(a, b, c+d) || isValid(a, b, c-d) || isValid(a, b, c*d) || isValid(a, b, c/d)) return true;
        return false;
    }
    
    bool isValid(int a, int b, int c){
        if( isValid(a+b, c) || isValid(a-b, c)  || isValid(a*b, c) || ((a != 0 && b != 0) && isValid(a/b, c)) ) return true;
        if( isValid(a+c, b) || isValid(a-c, b) || isValid(a*c, b) || ((a != 0 && c != 0) && isValid(a/c, b)) ) return true;
        if( isValid(a, b+c) || isValid(a, b-c) || isValid(a, b*c) || ((c != 0 && b != 0) && isValid(b/c, a)) ) return true;
        return false;
    }
    
    bool isValid(int a, int b){
        if((a + b == 24) || (a - b == 24) || (a * b == 24) || ((a != 0 && b != 0) && (a/b == 24))){
            return true;
        }
        return false;
    }
      
};
