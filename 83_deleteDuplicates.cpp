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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* ans = slow;
        int p = head->val;
        head = head->next;
        while(head!=nullptr) {
            if(head->val!=p) {
                p = head->val;
                slow->next = head;
                slow = slow->next;
            }
            head = head->next; 
        }
        slow->next = nullptr;
        return ans;
    }
};