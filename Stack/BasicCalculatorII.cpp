// https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
   int calculate(string s) {
    /*
    "3+2*2
    1. Create a vector of strings: "3", +, 2, *, 2
    2. Iterate through the strings:
        -If it's a num, push it on the stack
        -If its a "+", push next num onto the stack
        -If its a "-", push next num *-1 onto the stack
        -If its a "*", multiply top element with next num and pop stack, and push result on stack
        -If its a "/", divide top elem by the next num, pop stack, and push result on stack

    3. Iterate through stack, adding the elements together
    */

    //step 1
    vector<string> strings;
    string strNum = "";
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            strNum += s[i];
        }
        else {
            if (s[i] == ' ') {
                continue;
            }
            strings.push_back(strNum);
            strNum = "";
            string strOp = ""; strOp += s[i];
            strings.push_back(strOp);
        }
    }
    if (strNum != "") {
        strings.push_back(strNum);
    }

    //step 2
    stack<int> stk;
    for (int i = 0; i < strings.size();) {
        string cur = strings[i];
        if (cur == "+") {
            stk.push(stoi(strings[i + 1]));
            i += 2;
        }
        else if (cur == "-") {
            stk.push(stoi(strings[i + 1]) * -1);
            i += 2;
        }
        else if (cur == "*") {
            int top = stk.top();
            stk.pop();
            stk.push(top * stoi(strings[i + 1]));
            i += 2;
        }
        else if (cur == "/") {
            int top = stk.top();
            stk.pop();
            stk.push(top / stoi(strings[i + 1]));
            i += 2;
        }
        else { //its a number
            stk.push(stoi(strings[i]));
            ++i;
        }
    }

    //step 3
    int res = 0;
    while (!stk.empty()) {
        int top = stk.top();
        res += top;
        stk.pop();
    }
    return res;
}
};
