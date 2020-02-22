//https://leetcode.com/problems/merge-k-sorted-lists
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
   struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
    
       // shortcut for edge cases. 
       if (lists.size() == 0) return NULL;
       if (lists.size() == 1) return lists[0]; 
       
       // initialize the maxHeap. 
       priority_queue<ListNode*, std::vector<ListNode*>, comparator> maxHeap;
       
       // push the head of each of the items in list. 
       for (int i = 0; i< lists.size(); i++)
       {
           if (lists[i]!= NULL) maxHeap.push(lists[i]);
       }
       
       // shortcut if we failed to find even one valid list. 
       if (maxHeap.size() == 0) return NULL;
       
       // build the empty node as the return pointer.
       ListNode returnVal = ListNode(-1), *tmp = &returnVal; 
      
       // loop until the heap is empty. 
       while (maxHeap.size() >0)
       {
           tmp->next = maxHeap.top();
           maxHeap.pop();
           tmp = tmp->next;
           if (tmp->next != NULL && maxHeap.size()!=0)
           {
               maxHeap.push(tmp->next);
           }
       }
       
       return returnVal.next;
    }
};
