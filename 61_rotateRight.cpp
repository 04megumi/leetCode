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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* cur1 = head; ListNode* cur2 = head;
        int s = 1;
        while(cur1->next != nullptr) {s++; cur1 = cur1->next;}
        k %= s;
        if(!k) return head;
        k = (s-k);
        while(--k) cur2 = cur2->next;
        ListNode* t = cur2;
        cur2 = cur2->next;
        t->next = nullptr;
        cur1->next = head;
        return cur2;
    }
};