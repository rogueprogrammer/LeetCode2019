// https://leetcode.com/problems/middle-of-the-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /*
        
        1 -> 2 -> 3 -> 4 -> 5 -> 6
        s         f
             s              f 
                  s                   f
        
        */
        if(!head){
            return NULL;
        }
        ListNode* s = head;
        ListNode* f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
        
        
    }
};
