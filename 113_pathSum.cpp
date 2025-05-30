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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root,targetSum,ans,temp);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& temp) {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left&&!root->right&&targetSum==root->val) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left) dfs(root->left,targetSum-root->val,ans,temp);
        if(root->right) dfs(root->right,targetSum-root->val,ans,temp);
        temp.pop_back();
    }
};