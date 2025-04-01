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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size()-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if(l==r) {
            return lists[l];
        }
        if(l>r) {
            return nullptr;
        }
        int mid = (l+r)/2;
        ListNode* l1 = mergeKLists(lists, l, mid);
        ListNode* l2 = mergeKLists(lists, mid+1, r);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* pre = ans;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val < list2->val) {
                pre->next = list1;
                list1 = list1->next;
            } else {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }

        if(list1!=nullptr) {
            pre->next = list1;
        } else {
            pre->next = list2;
        }
        
        return ans->next;
    }
};
