// https://leetcode.com/problems/power-of-two/
class Solution {
public:
    
    /*
        number of bits equal to 1 is 1 for a power of 2   
        
        Alternatively, can also do n & (n-1) == 0
        
        n = 8, n-1 = 7
        
        1000
        0111
        0000
        
        
        
        
    */
    
    void rec(int n, int& count){
        if(n > 1){
            rec(n/2, count);
        }
        if(n % 2 == 1){
            ++count;
        }
    }
    
    int countBits(int n){
        int count = 0;
        rec(n, count);
        return count;
    }
    
    
    bool isPowerOfTwo(int n) {
        if(n == 1){
            return true;
        }
        return countBits(n) == 1;
    }
};
