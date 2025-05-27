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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        dfs(root,1,ans);
        return ans;
    }
    void dfs(TreeNode* root, int cur, int& ans) {
        if(!root->left&&!root->right) {
            ans = max(ans,cur);
            return;
        }
        if(root->left) dfs(root->left, cur+1, ans);
        if(root->right) dfs(root->right, cur+1, ans);
    }
};