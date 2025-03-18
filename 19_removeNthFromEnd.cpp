class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> queue(n+1, nullptr);
        ListNode* cur = new ListNode(0, head);
        unsigned short r = 0, l = 0;
        bool isStart = false;
        while(cur!=nullptr) {
            if(r==l && isStart) {
                queue[r] = cur;
                r = (r+1)%(n+1), l = (l+1)%(n+1);
            } else {
                isStart = true;
                queue[r] = cur;
                r = (r+1)%(n+1);
            }
            cur = cur->next;
        }
        if(queue[l]->next==head) return queue[l]->next->next;
        queue[l]->next = queue[l]->next->next;
        return head;
    }
};
