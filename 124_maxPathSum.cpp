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
    int ans = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int t = root->val;
        int l = max(dfs(root->left),0), r = max(dfs(root->right),0);
        ans = max(ans,t+l+r);
        return t + max(l,r);
    }
};