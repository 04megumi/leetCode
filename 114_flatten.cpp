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
    void flatten(TreeNode* root) {
        TreeNode* pre = new TreeNode(0);
        dfs(root,pre);
    }
    void dfs(TreeNode* root, TreeNode*& pre) {
        if(!root) return;
        TreeNode* l = root->left, *r = root->right;
        root->left = nullptr;
        pre->right = root;
        pre = root;
        if(l) {
            dfs(l,pre);
        }
        if(r) {
            dfs(r,pre);
        }
    }
};