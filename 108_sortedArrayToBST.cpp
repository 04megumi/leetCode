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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums,0,nums.size()-1);
    }
    TreeNode* recur(vector<int>& nums, int s, int e) {
        if(s>e) return nullptr;
        int m = (s+e)>>1;
        TreeNode* t = new TreeNode(nums[m]);
        t -> left = recur(nums,s,m-1);
        t -> right = recur(nums,m+1,e);
        return t;
    }
};