// https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res = 0;
        if(tokens.size() == 0){
            return 0;
        }
        
        for(string token : tokens){
            
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                int num = stoi(token);
                s.push(num);
            } else{
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                int res = 0;
                
                if(token == "+"){
                    res = num1 + num2;
                } else if(token == "-"){
                    res = num1 - num2;
                } else if(token == "*"){
                    res = num1 * num2;
                } else{ // division operator /
                    if(num2 == 0){
                        res = 0;
                    } else{
                        res = num1 / num2;
                    }
                }
                s.push(res);
                
            }
            
            
        }
                
        return s.top();
    }
};
