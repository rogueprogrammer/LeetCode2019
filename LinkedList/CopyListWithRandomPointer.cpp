//https://leetcode.com/problems/copy-list-with-random-pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {

    /*
    &1            &2         &3           &4
    1,2, 3        2,3,4      3,4,3        4,null,1
    cur
    While iterating through the linked list, you can't just copy the node's next and random 
    pointers, since the addrsses are of the inputted linked list. So create a hashtable of original list nodes to copied list nodes, 
    and copy the corresponding node, after making a copy of all the original nodes.
    */
    unordered_map<Node*, Node*> ht;
    Node* cur = head;
    Node* res;
    int i = 0;
    while (cur) {
        Node* copy = new Node(cur->val, NULL, NULL);
        ht[cur] = copy;
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        Node* copy = ht[cur];
        copy->next = ht[cur->next];
        copy->random = ht[cur->random];
        cur = cur->next;
    }
    return ht[head];
}
};
