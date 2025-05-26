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
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    bool dfs(TreeNode* root, int start, int end) {
        if(!root) return false;
        if(root->val>end||root->val<start) return false;
        if(root->left&&(root->val==INT_MIN||!dfs(root->left,start,root->val-1))) return false;
        if(root->right&&(root->val==INT_MAX||!dfs(root->right,root->val+1,end))) return false;
        return true;
    }
};