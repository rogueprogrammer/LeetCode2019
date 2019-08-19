/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //https://leetcode.com/problems/range-sum-of-bst
 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if(root == NULL) return sum;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->val >= L && cur->val <= R){
                sum += cur->val;
            }
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
            
        }
        return sum;
    }
};
