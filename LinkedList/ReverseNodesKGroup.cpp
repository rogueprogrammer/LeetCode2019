//https://leetcode.com/problems/reverse-nodes-in-k-group/
// (NOT SUBMITTED, But rough algo should work)

ListNode* reverseList(ListNode* head, ListNode* lastNode) {
    if (!head) return NULL;
    ListNode* n1 = head;
    ListNode* n2 = head->next;
    if (!n2) return n1;
    ListNode* n3 = head->next->next;
    /*
    1 <- 2 <- 3    -> NULL
            n1      n2

    */
    n1->next = NULL;
    while (n2 != lastNode) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3 != lastNode) {
            n3 = n3->next;
        }
    }
    if (n2 == lastNode) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3 != lastNode) {
            n3 = n3->next;
        }
    }
    return n1;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return NULL;
    ListNode* n1 = head;

    ListNode* n2 = head->next;
    if (!n2) return head;
    ListNode* n3 = n2;
    ListNode* res = n1;
    int groupNum = 0;
    while (n3) {
        for (int i = 0; i < k - 2; ++i) {
            n2 = n2->next;
        }
        n3 = n2->next;
        ListNode* root = reverseList(n1, n2); // reverse list from n1 to n2
        if (groupNum == 0) {
            res = root;
            ++groupNum;
        }
        while (root->next) {
            root = root->next;
        }
        root->next = n3;
        n1 = n3;
        n2 = n3->next;
    }
    return res;
}
