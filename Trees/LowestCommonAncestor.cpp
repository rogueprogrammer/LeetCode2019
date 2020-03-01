//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
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
    
    TreeNode* GetParent(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root == p || root == q || root == NULL){
            return root;
        }
        TreeNode* leftParent = GetParent(root->left, p, q);
        TreeNode* rightParent = GetParent(root->right, p, q);
        if(leftParent && rightParent){
            return root;
        }
        if(leftParent){
            return leftParent;
        }
        if(rightParent){
            return rightParent;
        }
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return GetParent(root, p, q);
    }
};
