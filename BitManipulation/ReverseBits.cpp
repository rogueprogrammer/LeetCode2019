// https://leetcode.com/problems/reverse-bits/submissions/
class Solution {
public:
    vector<bool> getBits(uint32_t n){
        vector<bool> bits(32, 0);
        int i = bits.size()-1;
        while(n >= 1){
            bits[i] = n % 2;
            n /= 2;
            --i;
        }
        
        return bits;
    }
    
    uint32_t reverseBits(uint32_t n) {
        vector<bool> bits = getBits(n);
        reverse(bits.begin(), bits.end());
                
        uint32_t res = 0;
        
        for(int i = 31; i >= 0; --i){
            if(bits[i] == 1){
                int exp = 31 - i;
                res += pow(2, exp);
            }
        }
        
        return res;
    }
};
