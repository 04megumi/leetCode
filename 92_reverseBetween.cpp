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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l=nullptr, *r=nullptr, *pre=nullptr;
        ListNode* ans = new ListNode(0,head);
        head = ans; int len = right - left;
        while(--left) head = head->next;
        l = head, r = head->next, head = head->next;
        for(int i=0;i<=len;i++) {
            ListNode* next = head->next;
            if(pre!=nullptr) head->next = pre;
            pre = head;
            head = next;
        }
        l->next = pre, r->next = head;
        return ans->next;
    }
};