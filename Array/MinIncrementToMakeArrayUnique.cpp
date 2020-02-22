//https://leetcode.com/problems/minimum-increment-to-make-array-unique/submissions/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) return 0;
        sort(A.begin(), A.end());
        set<int> seen;
        int maxValSeen = -1;
        int numMoves = 0;
        for(int i = 0; i < A.size(); ++i){ 
            int cur = A[i]; 
            auto it = seen.find(cur);
            if(it != seen.end()){ //already exists
                numMoves += (maxValSeen-cur+1); 
                cur = maxValSeen+1; 
            }
            maxValSeen = max(maxValSeen, cur);
            seen.insert(cur);
        }
        return numMoves;
    }
};
