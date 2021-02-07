// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        long lo = 0;
        long hi = x; //hi = 3, lo = 2, mid = 3
        // x = 8
        while(lo + 1 < hi){
            long mid = (lo+hi ) / 2; 
            long prod = mid * mid; // prod = 9
            if(prod == x){
                return (int)mid;
            }
            else if(prod > x){
                hi = mid;
            } else{
                lo = mid;
            }            
        }
        if(hi * hi == x){
            return (int)hi;
        }
        return (int)lo;
    }
};
