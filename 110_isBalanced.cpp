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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int a1 = dfs(root->left);
        int a2 = dfs(root->right);
        if(a1==-1||a2==-1||abs(a1-a2)>1) return -1;
        return max(a1,a2)+1;
    }
};