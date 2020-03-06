https://leetcode.com/problems/validate-binary-search-tree/

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
    /*
       5
    1    6
     3  4
    inorder traversal (left, root, right) will make tree in sorted order: 1, 3, 5, 4, 6
    verify if the ordering is in ascending order.
    */
    
    void inOrder(TreeNode* root, vector<TreeNode*>& order) {
        if (!root) {
            return;
        }
        if (root && root->left) {
            inOrder(root->left, order);
        }
        order.push_back(root);
        if (root && root->right) {
            inOrder(root->right, order);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> order;
        inOrder(root, order);
        for(int i = 1; i < order.size(); ++i){
            int j = i-1; TreeNode* prev = order[j]; TreeNode* cur = order[i];
            if(prev->val >= cur->val) return false;
        }
        return true;
    }
};
