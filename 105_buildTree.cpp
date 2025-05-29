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
    unordered_map<int,int> hash;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) hash[inorder[i]] = i;
        return recur(0,0,inorder.size()-1,preorder);
    }
    TreeNode* recur(int root,int left,int right,vector<int>& preorder) {
        if(left>right) return nullptr;
        TreeNode* t = new TreeNode(preorder[root]);
        int i = hash[preorder[root]];
        t -> left = recur(root+1,left,i-1,preorder);
        t -> right = recur(root+1+i-left,i+1,right,preorder);
        return t;
    }
};