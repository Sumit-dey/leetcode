class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *back = head, *front = head;
        int cnt = 0;
        while(cnt < n) ++cnt, front = front->next;

        ListNode *fake_head = new ListNode(0, head);
        ListNode *prev_back = fake_head;
        while(front != NULL) {
            front = front->next;
            back = back->next;
            prev_back = prev_back->next;
        }
        prev_back->next = back->next;
        delete back;
        ListNode *new_head = fake_head->next;
        delete fake_head;
        return new_head;
    }
};
