//https://leetcode.com/problems/serialize-and-deserialize-binary-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
     string res = "";
     if (!root) return res;
     queue<TreeNode*> q;
     queue<string> s;
     q.push(root); 
     string val = ","; val += to_string(root->val);
     s.push(val); //1
     res += to_string(root->val);
     while (!q.empty()) {
         TreeNode* top = q.front();
         q.pop();
         if (top->left) {
             q.push(top->left);
             string val = ",";
             val += to_string(top->left->val);
             s.push(val);
             res += val;
         }
         else {
             string val = ",null";
             s.push(val);
             res += val;
         }
         if (top->right) {
             q.push(top->right);
             string val = ",";
             val += to_string(top->right->val);
             s.push(val);
             res += val;
         }
         else {
             string val = ",null";
             s.push(val);
             res += val;
         }
     }
     return res;
 }

 vector<string> breakString(string data) {
     vector<string> v;
     string elem;
     for (int i = 0; i < data.size(); ++i) {
         if (data[i] == '[' ) {
             continue;
         }
         else if ( data[i] == ']') {
             v.push_back(elem);
             elem = "";
         }
         else if (data[i] != ',') {
             elem += data[i];
         }
         else {
             v.push_back(elem);
             elem = "";
         }
     }
     return v;
 }

 TreeNode* deserialize(string data) {
     //use a vector to store the split data
     //use a queue to keep track of the nodes.
     if(data=="") return NULL;
     vector<string> v = breakString(data);
     queue<TreeNode*> q;
     int i = 0;
     string first = v[i++];
     TreeNode* n = new TreeNode(stoi(first));
     TreeNode* res = n;
     q.push(n);
     while (!q.empty()) {
         n = q.front();
         if (i < v.size() && v[i] != "null") {
             TreeNode* l = new TreeNode(stoi(v[i]));
             n->left = l;
             q.push(l);
         }
         i++;
         if (i < v.size() && v[i] != "null") {
             TreeNode* r = new TreeNode(stoi(v[i]));
             n->right = r;
             q.push(r);
         }
         i++;
         q.pop();
     }
     return res;
 }
};

void main() {
    TreeNode* a = new TreeNode(1); 
    TreeNode* b = new TreeNode(2); 
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(NULL);
    a->left = b; a->right = c;
    c->left = d; c->right = e;
    d->left = f;
    ///cout << serialize(a) << endl;
    TreeNode* res = deserialize("[1,2,3,null,null,4,5]");
    cout << serialize(res) << endl;
}
