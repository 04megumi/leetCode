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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
    bool dfs(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left&&!root->right) return root->val==targetSum;
        if(root->left&&dfs(root->left,targetSum-root->val)) return true;
        if(root->right&&dfs(root->right,targetSum-root->val)) return true;
        return false;
    }
};