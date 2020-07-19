
// https://leetcode.com/problems/binary-tree-maximum-path-sum
// Do inorder traversal to come up with inorder array of values, then use dp to compute the max contiguous sum on the inorder array
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void Inorder(TreeNode* root, vector<int>& v) {
    if (!root) {
        return;
    }
    if (root->left) {
        Inorder(root->left, v);
    }
    v.push_back(root->val);
    if (root->right) {
        Inorder(root->right, v);
    }
}

int maxContiguousSum(vector<int>& v) {
    // [9, -10, 15, 20, 7, -1, 8]
    if (v.size() == 1) { return v[0]; }
    int res = INT_MIN;
    int sumAcc;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            sumAcc = v[0];
            res = sumAcc;
        }
        else {
            sumAcc = max(v[i], sumAcc + v[i]);
            res = max(res, sumAcc);
        }
    }
    return res;
}

int maxPathSum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    vector<int> v;
    Inorder(root, v);
    int maxSum = maxContiguousSum(v);
    return maxSum;
}


void main() {

    /*
         1
        / \
       -2   -3
       / \    \
       1  3   -2
          -1

    inorder traversal: 1, -2, 3, -1, 1, -3, -2
    */
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(-2);
    TreeNode* c = new TreeNode(-3);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(-1);
    TreeNode* g = new TreeNode(-2);
    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->right = g;
    e->right = f;
    maxPathSum(a);


    //vector<int> v = { 1, -2, 3, -1, 1, -3, -2 };
    //maxContiguousSum(v);
    system("PAUSE");
}
