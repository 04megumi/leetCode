/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* ans = new ListNode(0);
        ListNode* pre = ans;
        while(head) {
            if(head->val != val) {
                pre->next = head;
                pre = head;
            }
            head = head->next;
        }
        pre->next = nullptr;
        return ans->next;
    }
};