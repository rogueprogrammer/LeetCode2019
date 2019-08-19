  //https://leetcode.com/problems/jewels-and-stones/
  
  int numJewelsInStones(string J, string S) {
        unordered_map<char, int> ht;
        
        for(int i = 0; i < J.size(); ++i){
            char ch = J[i];
            ht[ch] = 0;
        }
        int numJewels = 0;
        for(int i = 0; i < S.size(); ++i){
            char ch = S[i];
            auto it = ht.find(ch);
            if(it != ht.end()){
                ++numJewels;
            }
        }
        return numJewels;
    }
