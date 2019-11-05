//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row
//passed all test cases
//idea: maintain count arrays for A and B, and same array for how many of the same values are shared at same index between A and b
// if n is the number of dice in A (and A.size should always equal B.size()), and if countA[i]+countB[i] - same[i] = n, then we can compute 
// the minimum number of rotations to get i as: n - max(countA[i], countB[i])
//O(n) solution

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7, 0);
        vector<int> countB(7, 0);
        vector<int> same(7, 0);
        if(A.size() != B.size()) return -1;
        int n = A.size();
        
        for(int i = 0; i < A.size(); ++i){
            int a = A[i];
            int b = B[i];
            countA[a]++;
            countB[b]++;
            if(a == b){
                same[a]++;
            }
        }
        int minNumRotations = INT_MAX;
        for(int i = 1; i <= 6; ++i){
            if(countA[i] + countB[i] - same[i] == n){
                minNumRotations = min(minNumRotations, 
                                     n - (max(countA[i], countB[i])));
            }
        }
        if(minNumRotations == INT_MAX) return -1;
        return minNumRotations;       
    }
};
