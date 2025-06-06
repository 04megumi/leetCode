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
private:
    int ans=0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* root, int cur) {
        int t = root->val + cur*10;
        if(!root->left&&!root->right) {
            ans += t;
            return;
        }
        if(root->left) dfs(root->left,t);
        if(root->right) dfs(root->right,t);
    }
};