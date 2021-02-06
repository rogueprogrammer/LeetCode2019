// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
class Solution {
public:
    string strMap = "0123456789abcdef";
    /*
    example: 26
    26%16 = 10 = a
    1%16 = 1
    
    10
    10%16 = 10 = a
    
    */
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        unsigned int n = num; // to handle negative numbers, this value holds 2s complement 
                              // of a negative integer. otherwise, positive nums stay same.
                              // for example: -3 becomes 2^32-3,which is 2s complement
                              // of 3 (flip all zeros to ones and vise versa, then add 1)
                              // 00000000 00000000 00000000 00000011
                              // 11111111 11111111 11111111 11111101
                              // which is 4294967293 in decimal
        
        string res = "";
        
        while(n >= 1){
            int in = n % 16;
            res += strMap[in];
            n /= 16;
        }
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};
