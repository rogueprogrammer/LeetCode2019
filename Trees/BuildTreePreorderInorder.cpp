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
    
     TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder,
     int preorderIndex, int inorderS, int inorderE) {
         if (preorderIndex >= preorder.size() || inorderS > inorderE ){
             return NULL;
         }
         int root = preorder[preorderIndex];
         int i = 0;
         for (i = 0; i < inorder.size(); ++i) { if (inorder[i] == root) { break; } }
         TreeNode* res = new TreeNode(root);
         res->left = buildSubtree(preorder, inorder, preorderIndex + 1, inorderS, i - 1);
         int left = i - inorderS;
         res->right = buildSubtree(preorder, inorder, preorderIndex + left + 1, i + 1, inorderE);
         return res;
 }

 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     if (preorder.size() == 0 || inorder.size() == 0) {
         return NULL;
     }
     return buildSubtree(preorder, inorder, 0, 0, inorder.size() - 1);
 }
};
