// https://leetcode.com/problems/generate-parentheses/submissions/

void backtrack(vector<string>& res, string str, int open, int close, int max) {
    if (str.length() == max * 2) { // base case
        res.push_back(str);
        return;
    }
    /* 
     constraints: - number of open parens should always be less than max
                  - number of close parens should always be less than open parens
    */
    
    if (open < max){
        backtrack(res, str + "(", open + 1, close, max);
    }
    if (close < open){
        backtrack(res, str + ")", open, close + 1, max);
    }
}


vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}
