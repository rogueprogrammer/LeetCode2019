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

/*ITERATIVE SOLUTION:
Runtime: 160 ms, faster than 17.56% of C++ online submissions for Range Sum of BST.
Memory Usage: 41.2 MB, less than 90.91% of C++ online submissions for Range Sum of BST.
*/
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

/* 
RECURSIVE SOLUTION:
Runtime: 144 ms, faster than 84.09% of C++ online submissions for Range Sum of BST.
Memory Usage: 41.1 MB, less than 100.00% of C++ online submissions for Range Sum of BST.
*/
class Solution {
public:
    int sumUtil(TreeNode* root, int L, int R){
        if(root == NULL) return 0;
        if(root->val >= L && root->val <= R){
            return root->val + sumUtil(root->left, L, R) + sumUtil(root->right, L, R);
        } else{
            return sumUtil(root->left, L, R) + sumUtil(root->right, L, R);
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if(root == NULL) return sum;
        return sumUtil(root, L, R);   
    }
};

