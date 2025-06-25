/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        int c1 = 0, c2 = 0;
        while(t1) {
            c1++;
            t1 = t1->next;
        }
        while(t2) {
            c2++;
            t2 = t2->next;
        }
        if(c1 > c2) {
            int d = c1 - c2;
            for(int i=0;i<d;i++) headA = headA->next;
        } else {
            int d = c2 - c1;
            for(int i=0;i<d;i++) headB = headB->next;
        }
        ListNode* ans = nullptr;
        while(headA) {
            if(headA==headB) {
                ans = headA;
                return ans;
            }
            headA = headA->next, headB = headB->next;
        }
        return ans;
    }
};