//https://leetcode.com/problems/recover-binary-search-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
        inorder: left, root, right
        
        50
        
           60 
       80     70
            65    55     (80, 55 were swapped)
            
        Inorder: 50, 80, 60, 65, 70, 55
                 50, 55, 60, 65, 70, 80
        Do an inorder traversal, and see which nodes need to be swapped to be in increasing order. 
        Traverse tree again and look for the two nodes, swapping their values.
    */
    
    void InorderTraversal(TreeNode* root, vector<int>& inorder){
        if(!root){
            return;
        }
        if(root->left){
            InorderTraversal(root->left, inorder);
        }
        inorder.push_back(root->val);
        if(root->right){
            InorderTraversal(root->right, inorder);
        }
    }
    
    
    void TraverseAndSwap(TreeNode* root, int p1, int p2){
        if(!root) return;
        if(root->val == p1){
            root->val = p2;
        } else if(root->val == p2){
            root->val = p1;
        }
        TraverseAndSwap(root->left, p1, p2);
        TraverseAndSwap(root->right, p1, p2);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        vector<int> inorder;
        InorderTraversal(root, inorder);
        int p1 = INT_MIN; int p2 = INT_MIN;
        for(int i = 0; i < inorder.size(); ++i){
            if(i == 0){
                if(inorder[i] > inorder[i+1]){
                    p1 = inorder[i];
                }
            } else if(i == inorder.size()-1){
                if(inorder[i] < inorder[i-1]){
                    p2 = inorder[i];
                }
            } else{
                if(inorder[i] > inorder[i+1] || inorder[i] < inorder[i-1]){
                    if(p1 == INT_MIN){
                        p1 = inorder[i];
                    } else{
                        p2 = inorder[i];
                    }
                }
            }
        }
        
        // traverse tree to swap the values
        TraverseAndSwap(root, p1, p2);
    }
};
