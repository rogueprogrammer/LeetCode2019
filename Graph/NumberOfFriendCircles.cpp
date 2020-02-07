#include "header.h"
//https://leetcode.com/problems/friend-circles
class Solution {
public:
    
    void dfs(vector<vector<int>>& M, int curFriend){
        vector<int> friends = M[curFriend];
        for(int i = 0; i < friends.size(); ++i){
            if(friends[i] == 1){
                //visit the node
                M[curFriend][i] = 0;
                dfs(M, i);
            }
        }        
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int numFriendCircles = 0;
        for(int i = 0; i < M.size(); ++i){
            for(int j = 0; j < M.size(); ++j){
                if(M[i][j] == 1){
                    dfs(M, i);
                    ++numFriendCircles;
                }
            }
        }
        return numFriendCircles;
    }
};
