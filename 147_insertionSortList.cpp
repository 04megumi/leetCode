class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while (head) {
            ListNode* next = head->next;
            ListNode* t = dummy;
            while (t->next && t->next->val < head->val) {
                t = t->next;
            }
            head->next = t->next;
            t->next = head;
            head = next;
        }
        return dummy->next;
    }
};