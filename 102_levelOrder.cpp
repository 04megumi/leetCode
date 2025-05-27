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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> t1, t2;
        if(root) t1.push(root);
        while(!t1.empty()||!t2.empty()) {
            vector<int> temp;
            if(!t1.empty()) {
                while(!t1.empty()) {
                    TreeNode* t = t1.front();
                    t1.pop();
                    temp.push_back(t->val);
                    if(t->left) t2.push(t->left);
                    if(t->right) t2.push(t->right);
                }
            } else {
                while(!t2.empty()) {
                    TreeNode* t = t2.front();
                    t2.pop();
                    temp.push_back(t->val);
                    if(t->left) t1.push(t->left);
                    if(t->right) t1.push(t->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};