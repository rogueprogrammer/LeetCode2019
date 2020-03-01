//https://leetcode.com/problems/valid-parentheses/submissions/
class Solution {
public:
    /*
        Idea:
        Maintain a stack of all the open parens.
        Eachtime a closed paren is seen, if the top of stack matches the closed paren, pop off stack.
        Else return false.
    */
    bool isValid(string s) {
        
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i){
            char cur = s[i];
            if(cur == '(' || cur == '[' || cur == '{'){
                stk.push(cur);
            }
            else if(cur == ')'){
                if(stk.empty()) return false;
                char top = stk.top();
                if(top == '('){
                    stk.pop();
                } else{
                    return false;
                }
            }
            else if (cur == ']'){
                if(stk.empty()) return false;
                char top = stk.top();
                if(top == '['){
                    stk.pop();
                } else{
                    return false;
                }
            }
            else if( cur == '}'){
                if(stk.empty()) return false;
                char top = stk.top();
                if(top == '{'){
                    stk.pop();
                } else{
                    return false;
                }
            } 
        }
        return stk.empty();
    }
};
