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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre1 = new ListNode(0); 
        ListNode* pre2 = new ListNode(0);
        ListNode* t1 = pre1, *t2 = pre2;
        while(head!=nullptr) {
            if(head->val<x) {
                t1->next = head;
                t1 = t1->next;
                head = head->next;
                t1->next = nullptr;
            } else {
                t2->next = head;
                t2 =t2->next;
                head = head->next;
                t2->next = nullptr;
            }
        }
        t1->next = pre2->next;
        return pre1->next;
    }
};