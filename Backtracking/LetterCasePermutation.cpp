// https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    
    vector<string> res;
    
    /* typical recursion/backtracking
    
        a1b2                    i = 0, two choices, a and A
  a1b2         A1b2             i = 1, go to next index
a1b2  a1B2    A1b2    A1B2      i = 2, two choices, b and B
a1b2  a1B2    A1b2    A1B2      i = 3, no choices, go to next index
                                i = 4, i >= s.size => return leaf node (which is just s)
    */
    
    
    // s is the object to modify, index is the index within s to modify
    void helper(string s, int index){
        
        //base case
        if(index >= s.size()){
            res.push_back(s);
            return;
        }
        
        if(isalpha(s[index])){
            if(islower(s[index])){
                helper(s, index+1);
                s[index] = toupper(s[index]);
                helper(s, index+1);
                //change state back
                s[index] = tolower(s[index]);
            } else{
                helper(s, index+1);
                s[index] = tolower(s[index]);
                helper(s, index+1);
                //change state back
                s[index] = toupper(s[index]);
            }
        } else{
            helper(s, index+1);
        }
        
    }
    
    vector<string> letterCasePermutation(string S) {
        helper(S, 0);
        return res;
    }
};
