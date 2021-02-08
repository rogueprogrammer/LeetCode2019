// https://leetcode.com/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    /*
    Floyd's cycle detection algorithm:
    find intersection node with fast and slow pointer
    create a start pointer at head, and keep moving start pointer as well as intersection node
    one at a time. once they intersect, the start of the cycle is found. 
    */
    
    ListNode* findIntersection(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast->next && fast->next->next){
            slow = slow->next;
            
            fast = fast->next->next;
             
            if(slow == fast){
                return slow;
            }
            
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* intersection = findIntersection(head);
        if(intersection == NULL){
            return NULL;
        }
        ListNode* start = head;
        while(start != intersection){
            start = start->next;
            intersection = intersection->next;
        }
        return start;
    }
};
