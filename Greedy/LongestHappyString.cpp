/* 
30/34
https://leetcode.com/problems/longest-happy-string/submissions/
*/

class Solution {
public:
    
    /*
    Greedily choose the highest one until all are 0
    a = 1, b = 1, c = 7
    
    c
    a = 1, b = 1, c = 6
    
    cc
    a = 1, b = 1, c = 5
    
    cca
    a = 0, b = 1, c = 5
    
    ccac
    a = 0, b = 1, c = 4
    
    ccacc
    a = 0, b = 1, c = 3
    */
    
    bool isThreeInRow(string s, char c){
        s += c;
        int len = s.size();
        if(len < 3){
            return false;
        }
        if((s[len-1] == s[len-2]) && (s[len-2] == s[len-3])){
            return true;
        }    
        return false;
    }
    
    int getHighest(int a, int b, int c, string s){
        int highest = -1;
        while(highest == -1){
            highest = max(max(a, b), c);
            if(highest == a){
                if(isThreeInRow(s, 'a')){
                    highest = max(b,c);
                }    
            }
            if(highest == b){
                if(isThreeInRow(s, 'b')){
                    highest = max(a, c);
                }
            }
            if(highest == c){
                if(isThreeInRow(s, 'c')){
                    highest = max(a,b);
                }
            }
            
        }
        return highest;
    }
    
    
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        
        while(1){
            if (a == 0 && b == 0 && c == 0){
                break;
            }        
            int choice = getHighest(a,b,c, res);
            if ((choice == -1) || (choice == 0)) {
                break;
            }
            if (choice == a){
                res += "a";
                --a;
            } else if(choice == b){
                res += "b";
                --b;
            } else{
                res += "c";
                --c;
            }
        }
        
        return res;
    }
};
