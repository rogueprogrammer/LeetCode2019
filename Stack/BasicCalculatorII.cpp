// https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    
    
    int calculate(string s) {
        int res = 0;
        /*
        30+5/2
        stack: 30, 2
        Parse string, and each time you see *, /, then you push the result on the stack.
        If you see subtraction sign, then make the next integer negative and push it on stack.
        Add all integers on the stack.
        */
        stack<int> stk;
        int i = 0;
        string strNum = "";
        while(i < s.size()){
            if(isdigit(c)){
                strNum += c;
            } else if(c == ' '){ 
               continue;   
            }
            else {
                    int curNum = stoi(strNum);
                    stk.push(curNum);
                    strNum = "";
                
                    int nextNum;
                    while(i < s.size() && s[i] == ' '){
                        i++;
                    }
                    nextNum = s[i] - '0';
                    if(c == '+'){
                       continue;
                    } else if(c == '-'){
                        stk.push(nextNum * -1);
                    } else if(c == '*'){
                        int top = stk.top();
                        stk.pop();
                        stk.push(top * nextNum);
                    } else if(c == '/'){
                        int top = stk.top();
                        stk.pop();
                        stk.push(top / nextNum);
                    }
                }
        }
        
        return res;
    }
};
