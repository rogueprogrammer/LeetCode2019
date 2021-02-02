//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
   int myAtoi(string s) {

    int i = 0;
    long res = 0;
    bool negative = false;
    bool leadingByLetters = false;
    bool positive = false;
    bool leadingByNumbers = false;
    while (i < s.size()) {
        if(s[i] == '+'){
            if(negative){
                return 0;
            }
            positive = true;
            ++i;
            continue;
        }
        if (s[i] == '-') {
            if(positive){
                return 0;
            }
            negative = true;
            ++i;
            continue;
        }
        if(s[i] == '.'){
            return res;
        }
        if (s[i] == ' ') {
            ++i;
            continue;
        }

        if (!isdigit(s[i])) {
            ++i;
            leadingByLetters = true;
            continue;
        }
        if (res == 0 && leadingByLetters) {
            return 0;
        }
        if(!leadingByLetters){
            leadingByNumbers = true;
        }
        int digit = s[i] - '0';
        res = (res * 10) + digit; //4
        ++i;
    }
    if(negative){
        res *= -1;
    }
    if(res < -2147483648){
        return -2147483648; 
    }   
    if(res > 2147483647){
        return 2147483647;
    }
    return res;
}


};
