//https://leetcode.com/problems/repeated-dna-sequences/
//figure out bit manipulation technique
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        /*
        1. Find all substrings of length 10, store them in our hashtable.
        2. If there's a collision (it already exists, then we add that to our resulting list)
        */
        set<string> subsequences;
        set<string> repeatedSubsequences;
        vector<string> res;
        if(s.size() < 10) return res;
        for(int i = 0; i <= s.size()-10; ++i){
            string curSubstring = s.substr(i, 10);
            auto it = subsequences.find(curSubstring);
            if(it == subsequences.end()){
                subsequences.insert(curSubstring);
            } else{
                repeatedSubsequences.insert(curSubstring);
            }
        }
        for(auto it = repeatedSubsequences.begin(); it != repeatedSubsequences.end(); ++it){
            res.push_back(*it);
        }
        return res;
    }
};
