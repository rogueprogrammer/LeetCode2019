// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    
    /*
    d   v   d   d   f   g
               l        r 

    set={ d, f, g }
    res = 3
    
    Idea is to use a sliding window approach, increase the right pointer each time the window 
    is expanded. Invariant is that the window only contains unique characters. That means that 
    at any given time, the size of the window is the size of the number of unique characters.
    As soon as duplicate character is encountered. Increment left pointer and remove the char at left pointer in the window, while constantly checking if the character at right pointer is duplicate.
    O(n) runtime and space.
    
    */
    
    
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r = 0;
        int res = 0;
        set<char> se;
        int n = s.size();
        while(r < n){
            char cur = s[r];
            auto it = se.find(cur);
            if(it == se.end()){ // not in set
                se.insert(cur);
                ++r;
                int curSize = se.size();
                res = max(res, curSize);
            } else{
                se.erase(s[l]);
                ++l;
            }
            
        }
                
        return res;
    }
};
