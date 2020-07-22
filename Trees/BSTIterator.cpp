// https://leetcode.com/problems/binary-search-tree-iterator/submissions/
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

  /*
               7
          5              15
        4    6         9      30
     3     5.9    6.5             40
          5.8
          
stk: 6, 7
Requirement is to maintain only O(h) memory and perform in O(1) time. Maintain a stack of only
left subtree. Each time next() is called, push elem on stack and check if it has right subtree, if it
does, then left boundry of the right subtree needs to be pushed on the stack. 
Amortized runtime for next() and hasNext is O(1)
        
        */
class BSTIterator {
public:
    stack<TreeNode*> s;
    int lastPopped;
    
    BSTIterator(TreeNode* root) {
       pushLeftBoundryOnStk(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n = s.top();
        s.pop();
        if(n->right){
            pushLeftBoundryOnStk(n->right);
        }
        return n->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.empty() == false;
    }
    
    void pushLeftBoundryOnStk(TreeNode* root){
        if(!root) return;
        s.push(root);
        if(root->left){
            pushLeftBoundryOnStk(root->left);
        }
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
