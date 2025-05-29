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
    unordered_map<int, int> hash;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) hash[inorder[i]] = i;
        return recur(postorder.size()-1,0,postorder.size()-1,postorder);
    }
    TreeNode* recur(int root, int left, int right, vector<int>& postorder) {
        if(left>right) return nullptr;
        TreeNode* t = new TreeNode(postorder[root]);
        int i = hash[postorder[root]];
        t -> left = recur(root-1-right+i,left,i-1,postorder);
        t -> right = recur(root-1,i+1,right,postorder);
        return t;
    }
};