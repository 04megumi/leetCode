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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
    vector<TreeNode*> dfs(int s, int e) {
        vector<TreeNode*> ans;
        if(s>e) {
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=s;i<=e;i++) {
            vector<TreeNode*> l = dfs(s,i-1);
            vector<TreeNode*> r = dfs(i+1,e);
            for(auto& t1 : l) {
                for(auto& t2 : r) {
                    TreeNode* t = new TreeNode(i);
                    t->left = t1, t->right = t2;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};