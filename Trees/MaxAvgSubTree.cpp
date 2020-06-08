// https://leetcode.com/problems/maximum-average-subtree/submissions/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
    5
   10      8
 6   3    7    12

 5 => 10+6+3+8+7+12+5/7 = 51/7 = 7.
 10 => 6+3+10/3 = 19/3 = 6.33
 8 => 8+7+12/3 = 9

 Using post-order traversal, First compute the sum of each node's subtree, 
 then compute the number of nodes for each node's subtree.  
 Then iterate through the maps and compute the maxavg.
*/


unordered_map<TreeNode*, int> sumMap;
unordered_map<TreeNode*, int> numNodesMap;

//store the sum for every node into sumMap using post-order traversal on the tree
double utilSum(TreeNode* root) {
    if (root != NULL) {
        double leftSum = utilSum(root->left);
        double rightSum = utilSum(root->right);
        double curSum = root->val + leftSum + rightSum;
        sumMap[root] = curSum;
        return curSum;
    }
    else {
        return 0;
    }
}

int utilNumNodes(TreeNode* root) {
    if (root != NULL) {
        int leftNumNodes = utilNumNodes(root->left);
        int rightNumNodes = utilNumNodes(root->right);
        int curNumNodes = leftNumNodes + rightNumNodes + 1;
        numNodesMap[root] = curNumNodes;
        return curNumNodes;
    }
    else {
        return 0;
    }
}

double maximumAverageSubtree(TreeNode* root) {
    double res = 0;
    if (!root) {
        return res;
    }
    utilSum(root);
    utilNumNodes(root);

    for (auto it = sumMap.begin(); it != sumMap.end(); it++) {
        TreeNode* cur = it->first;
        double sum = (double)sumMap[cur];
        int numNodes = numNodesMap[cur];
        double avg = sum / numNodes;
        res = max(res, avg);
    }
    return res;
}


void main() {

    TreeNode* a = new TreeNode(5);
    TreeNode* b = new TreeNode(10);
    TreeNode* c = new TreeNode(8); 
    TreeNode* d = new TreeNode(6); 
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(7);
    TreeNode* g = new TreeNode(2);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;
    /*utilNumNodes(a);
    for (auto it = numNodesMap.begin(); it != numNodesMap.end(); it++) {
        cout << it->first->val << " , " << it->second << endl;
    }*/
    cout << maximumAverageSubtree(a) << endl;

    system("PAUSE");
}
