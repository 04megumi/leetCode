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
        ListNode* slow = new ListNode(0);
        ListNode* pre = slow;
        while(head!=nullptr) {
            if(head->next==nullptr) {
                slow->next = head;
                slow=slow->next;
                break;
            }
            if(head->val==head->next->val) {
                int p =head->val;
                while(head->next!=nullptr&&head->next->val==p) head = head->next;
                if(head->next==nullptr) break;
                head = head->next;
            } else {
                slow->next = head;
                slow = slow->next;
                head = head->next;
            }
        }
        slow -> next = nullptr;
        return pre->next;
    }
};