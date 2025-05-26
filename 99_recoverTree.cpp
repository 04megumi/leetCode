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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;
        dfs(root, first, second, pre);
        swap(first->val, second->val);
    }
    void dfs(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& pre) {
        if(!root) return;
        if(root->left) dfs(root->left, first, second, pre);
        if(pre && root->val<=pre->val) {
            if(!first) {
                first = pre;
                second = root;
            } else {
                second = root;
            }
        }
        pre = root;
        if(root->right) dfs(root->right, first, second, pre);
    }
};