class Solution {

public:

    ListNode* merge(ListNode *L1, ListNode *L2) {
        ListNode *pseudoHead = new ListNode;
        ListNode *prev = pseudoHead;
        while(L1 != NULL or L2 != NULL) {
            ListNode *cur;

            if(L1 == NULL) cur = L2, L2 = L2->next;
            else if(L2 == NULL or L1->val <= L2->val) cur = L1, L1 = L1->next;
            else cur = L2, L2 = L2->next;

            prev->next = cur;
            prev = cur;
        }
        prev->next = NULL;
        ListNode* head = pseudoHead->next;
        delete pseudoHead;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        for(int sz = 1; sz < k; sz *= 2) {
            for(int i = 0; i+sz < k; i += sz*2) {
                lists[i] = merge(lists[i], lists[i+sz]);
            }
        }
        return lists[0];
    }
};
