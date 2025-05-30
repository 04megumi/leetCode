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
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int a1 = dfs(root->left);
        int a2 = dfs(root->right);
        if(!a1) return a2+1;
        if(!a2) return a1+1;
        return min(a1,a2)+1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> a1;
        queue<TreeNode*> a2;
        if(!root) return 0;
        int ans = 0;
        a1.push(root);
        while(!a1.empty()||!a2.empty()) {
            ans++;
            if(!a1.empty()) {
                while(!a1.empty()) {
                    if(!a1.front()->left&&!a1.front()->right) return ans;
                    if(a1.front()->left) a2.push(a1.front()->left);
                    if(a1.front()->right) a2.push(a1.front()->right);
                    a1.pop();
                }
            } else {
                while(!a2.empty()) {
                    if(!a2.front()->left&&!a2.front()->right) return ans;
                    if(a2.front()->left) a1.push(a2.front()->left);
                    if(a2.front()->right) a1.push(a2.front()->right);
                    a2.pop();
                }
            }
        }
        return ans;
    }
};