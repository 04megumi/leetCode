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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return recur(head,nullptr);
    }
    TreeNode* recur(ListNode* s, ListNode* e) {
        if(s==e) return nullptr;
        ListNode* m = findMid(s,e);
        TreeNode* t = new TreeNode(m->val);
        t->left = recur(s,m);
        t->right = recur(m->next,e);
        return t;
    }
    ListNode* findMid(ListNode* s, ListNode* e) {
        ListNode* fast = s, *slow = s;
        while (fast!=e && fast->next!=e) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int r = 0; ListNode* t = head;
        while(t) {r++; t=t->next;}
        return recur(head,1,r);
    }
    TreeNode* recur(ListNode*& h, int l, int r) {
        if(l>r) return nullptr;
        int m = (l+r) >> 1;
        TreeNode* t = new TreeNode();
        t->left = recur(h,l,m-1);
        t->val = h->val;
        h = h->next;
        t->right = recur(h,m+1,r);
        return t;
    }
};