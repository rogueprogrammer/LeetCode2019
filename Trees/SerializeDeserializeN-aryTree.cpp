//https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/
// (didn't submit). but general algo should work.
class Node {
public:
    int val;
    vector<Node*> children;


    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Encodes a tree to a single string.
string serialize(Node* root) {
    //idea - start off with the root, Do a BFS traversal, and maintain the BFS ordering
    // in a queue. update the resulting string while pushing nodes onto the queue
    string res = "[";
    queue<Node*> q;
    if (root) {
        q.push(root);
    }

    while (!q.empty()) {
        Node* top = q.front();
        if (top->val == INT_MIN) {
            q.pop();
            continue;
        }
        res += top->val;
        res += ",";

        for (int i = 0; i < top->children.size(); ++i) {
            q.push(top->children[i]);
        }
        q.push(new Node(INT_MIN)); //mark end of children

        q.pop();
    }
    res = res.substr(0, res.size() - 1); //remove the last comma
    res += "]";
    return res;
}

vector<int> breakString(string data) {
    vector<int> res;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == '[' || data[i] == ']') {
            continue;
        }
        string strVal = "";
        while (i < data.size() && data[i] != ',' && data[i] != ']') {
            strVal += data[i];
            i++;
        }
        int curVal = stoi(strVal);
        res.push_back(curVal);
    }
    return res;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if (data == "") return NULL;
    //"[1,2,3,4,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN]"
    vector<int> v = breakString(data);
    queue<Node*> q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i = 0;

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        while (v[i] != INT_MIN) {
            i++;
            Node* child = new Node(v[i]);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;

}
void main() {

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    vector<Node*> children;
    children.push_back(b);
    children.push_back(c);
    children.push_back(d);
    children.push_back(e);
    a->children = children;
    string res = serialize(a);
    cout << res << endl;
    Node* root = deserialize(res);
    system("PAUSE");
}
