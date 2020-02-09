//https://leetcode.com/problems/one-edit-distance/
//passed all test cases
bool isOneEditDistance(string s, string t) {
        if(s == "" && t == "") return false;
    
        for(int i =0 ; i < min(s.size(), t.size()); ++i){
            if(s[i] != t[i]){
                if(s.size() == t.size()){ //replace one of the strings
                    char diff = s[i];
                    t[i] = diff;
                    return s == t;
                } else if(s.size() < t.size()){
                    return t.substr(i+1) == s.substr(i);
                } else{
                    return s.substr(i+1) == t.substr(i);
                }
            }   
        }
        if(s.size() > t.size()){
            return s.size() - t.size() == 1;
        }   
        return t.size() - s.size() == 1;
    }
