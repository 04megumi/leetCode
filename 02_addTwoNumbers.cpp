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

/*
    || or && ?
    || 由于reminder可能一直和后续单链条进位，不好写，又要再来一个while，所以不如直接 &&
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* pre = new ListNode();
        pre = ans;
        int reminder = 0;
        while(l1!=nullptr || l2!=nullptr){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int add = val1 + val2 + reminder;
            ListNode* newNode = new ListNode(add%10);
            reminder = add / 10;
            pre -> next = newNode;
            pre = newNode;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(reminder){
            ListNode* newNode = new ListNode(reminder);
            pre->next = newNode;
        }
        return ans->next; //not ans but ans->next !!
    }
};
