class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) return head;
            
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* pre = dummy;
            
            while (head && head->next) {
                ListNode* first = head;
                ListNode* second = head->next;
                
                pre->next = second;
                first->next = second->next;
                second->next = first;
                
                pre = first;
                head = first->next;
            }
            
            return dummy->next;
        }
    };
