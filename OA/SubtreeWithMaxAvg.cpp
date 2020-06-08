// https://leetcode.com/discuss/interview-question/349617
//Find maximum average of subtree in an N-Ary tree 
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

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) {
        val = x;
    }
    TreeNode(int x, vector<TreeNode*> kids) {
        val = x;
        children = kids;
    }
};
unordered_map<TreeNode*, int> sumMap;
unordered_map<TreeNode*, int> numNodesMap;

//store the sum for every node into sumMap using post-order traversal on the tree
double utilSum(TreeNode* root) {
    if (root != NULL) {
        vector<TreeNode*> kids = root->children;
        double kidsSum = root->val;
        for (TreeNode* kid : kids) {
            double kidSum = utilSum(kid);
            kidsSum += kidSum;
        }
        sumMap[root] = kidsSum;
        return kidsSum;
    }
    else {
        return 0;
    }
}


int utilNumNodes(TreeNode* root) {
    if (root != NULL) {
        vector<TreeNode*> kids = root->children;
        int kidsCount = 1;
        for (TreeNode* kid : kids) {
            int kidSum = utilNumNodes(kid);
            kidsCount += kidSum;
        }
        numNodesMap[root] = kidsCount;
        return kidsCount;
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

    vector<TreeNode*> kids1; kids1.push_back(d); kids1.push_back(e);
    vector<TreeNode*> kids2; kids2.push_back(f); kids2.push_back(g);

    vector<TreeNode*> kids3; kids3.push_back(b); kids3.push_back(c);
    a->children = kids3;
    b->children = kids1;
    c->children = kids2;
    /*utilSum(a);
    
    for (auto it = sumMap.begin(); it != sumMap.end(); it++) {
        cout << it->first->val << " , " << it->second << endl;
    }*/
    cout << maximumAverageSubtree(a) << endl;

    system("PAUSE");
}
