//https://leetcode.com/problems/reverse-linked-list

ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        if(!n2) return n1;
        ListNode* n3 = head->next->next;
        /*
        1 <- 2 <- 3    -> NULL
                n1      n2
        */
        n1->next = NULL;
        while(n2 != NULL){
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if(n3 != NULL){
                n3 = n3->next;
            }
        }
        return n1;
    }
