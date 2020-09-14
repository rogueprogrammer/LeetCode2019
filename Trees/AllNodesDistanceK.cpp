/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void generateAdjGraph(TreeNode* root, map<int, vector<int>>& g){
        if(!root){
            return;
        }
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        generateAdjGraph(root->left, g);
        generateAdjGraph(root->right, g);
    }
    set<int> visited;
    
    void dfs(map<int, vector<int>> g, int curRoot, int k, vector<int>& res){
        visited.insert(curRoot);
        
        if(k == 0){
            res.push_back(curRoot);
            return;
        }
        
        vector<int> children = g[curRoot];
        for(int child : children){
            
            auto it = visited.find(child);
            if(it == visited.end()){
                dfs(g, child, k-1, res);
            }
        }
        
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        /*
        3:47
        - generate adjacency undirected graph 
        3 -> 5, 1
        5 -> 3, 2, 6
        1 -> 3, 0
        6 -> 5
        2 -> 5, 7, 4
        7 -> 2
        4 -> 2
        1 -> 3, 0, 8
        0 -> 1
        8 -> 1
        */
        map<int, vector<int>> g;
        generateAdjGraph(root, g);
        vector<int> res;
        dfs(g, target->val, K, res);
        return res;
    }
};

