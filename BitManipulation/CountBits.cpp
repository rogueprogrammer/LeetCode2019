// https://leetcode.com/problems/counting-bits/submissions/
class Solution {
public:
    
    void rec(int n, int& count){
        if(n > 1){
            rec(n/2, count);
        }
        if(n % 2 == 1){
            ++count;
        }
    }
    
    
    int num1s(int num){
        int count = 0;
        rec(num, count);
        return count;
    }
    
    
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; ++i){
            res.push_back(num1s(i));
        }
        return res;
    }
};
