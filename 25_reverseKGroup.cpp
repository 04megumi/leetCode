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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
            
        while (true) {
            auto [newHead, nextGroup] = basicReverse(head, k); 
            if (newHead == nullptr) break;
            prev->next = newHead;
            head->next = nextGroup;
            prev = head;
            head = nextGroup;
        }  
        return dummy.next;
    }
    
private:
    pair<ListNode*, ListNode*> basicReverse(ListNode* head, int k) {
        ListNode* pre = nullptr;
        ListNode* originalHead = head;
        
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == nullptr) return {nullptr, nullptr};
            check = check->next;
        }
        
        for (int i = 0; i < k; i++) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return {pre, head}; 
    }
};
