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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* pre = nullptr;
        if(!root) return ans;
        while(root || !st.empty()) {
            // 左边有节点就先遍历, pre为当前节点
            if(root->left) {
                pre = root;
                root = root->left;
                continue;
            }
            // 左边没有节点直接添加当前值
            ans.push_back(root->val);
            // 左边没有但有右边
            if(root->right) {
                root = root->right;
                continue; 
            }
            // 左右都没有
            if(st.empty()) break;
            root = st.top();
            st.pop();
            root->left = nullptr;
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(!root) return ans;
        while(root || !st.empty()) {
            // 左边有节点就先遍历并存储当前节点
            if(root->left) {
                st.push(root);
                root = root->left;
                continue;
            }
            // 左边没有节点直接添加当前值
            ans.push_back(root->val);
            // 左边没有但有右边
            if(root->right) {
                root = root->right;
                continue; 
            }
            // 左右都没有
            if(st.empty()) break;
            root = st.top();
            st.pop();
            root->left = nullptr;
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& ans) {
        if(root==nullptr) return;
        if(root->left!=nullptr) dfs(root->left,ans);
        ans.push_back(root->val);
        if(root->right!=nullptr) dfs(root->right,ans);
    }
};