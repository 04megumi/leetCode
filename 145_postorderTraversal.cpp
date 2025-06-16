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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; stack<TreeNode*> st;
        while(root||!st.empty()) {
            if(root) {
                if(!root->left&&!root->right) {
                    ans.push_back(root->val);
                    root = nullptr;
                    continue;
                }
                st.push(root);
                if(root->left) {
                    root = root->left;
                    st.top()->left = nullptr;
                    continue;
                }
                if(root->right) {
                    root = root->right;
                    st.top()->right = nullptr;
                }
            } else {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};