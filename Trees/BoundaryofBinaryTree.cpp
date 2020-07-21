#include "Header.h"
// https://leetcode.com/problems/boundary-of-binary-tree/
// (not finished, but close)
vector<int> boundaryOfBinaryTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* levelMark = new TreeNode(INT_MIN);
    q.push(levelMark);
    vector<int> s;

    while (!q.empty()) {
        TreeNode* front = q.front();
        s.push_back(front->val);
        if (front->val == INT_MIN) { //end of level
            if (q.size() > 1) { //if only element is -1 in queue, then we're done traversing
                q.push(new TreeNode(INT_MIN));
            }
        }
        if (front->left) {
            q.push(front->left);
        }
        if (front->right) {
            q.push(front->right);
        }
        q.pop();
    }
    // s: 1 , -1, 2, 3, -1, 4, 5, 6, -1, 7, 8, 9, 10, -1
    // push root: first elem
    // push left boundary: all elems right of -1
    // push all leaves: elems between last two -1s
    // push right boundary: all elems left of -1

    unordered_set<int> res;
    res.insert(s[0]);
    // left boundary
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == INT_MIN && i + 1 < s.size()) {
            res.insert(s[i + 1]);
        }
    }

    //push all leaves
    int lastMarker = -1;
    int secondLastMarker = -1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == INT_MIN) {
            if (lastMarker == -1) {
                lastMarker = i;
            }
            else {
                secondLastMarker = i;
            }
        }
        if (lastMarker != -1 && secondLastMarker != -1) {
            break;
        }
    }
    for (int i = secondLastMarker + 1; i < lastMarker; ++i) {
        res.insert(s[i]);
    }

    //right boundary:
    for (int i = s.size(); i >= 0; --i) {
        if (s[i] == INT_MIN && i - 1 >= 0) {
            res.insert(s[i - 1]);
        }
    }
    vector<int> finalResult(res.begin(), res.end());

    return finalResult;
}




void main() {
    
    /*
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10      
    */
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    TreeNode* h = new TreeNode(8);
    TreeNode* i = new TreeNode(9);
    TreeNode* j = new TreeNode(10);
    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f;
    e->left = g; e->right = h;
    f->left = i; f->right = j;
    vector<int> res = boundaryOfBinaryTree(a);


    system("PAUSE");
}
