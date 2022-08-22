class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;

        int sz = 0;
        ListNode *cur = head;
        while(cur != NULL) ++sz, cur = cur->next;
        k %= sz;
        if(k == 0) return head;

        ListNode *first = head;
        ListNode *second = head;
        while(k--) first = first->next;

        while(first->next != NULL) first = first->next, second = second->next;
        first->next = head;
        ListNode *new_head = second->next;
        second->next = NULL;
        return new_head;
    }
};
