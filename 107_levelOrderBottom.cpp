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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> temp;
        if(!root) return vector<vector<int>> {temp.begin(), temp.end()};
        queue<TreeNode*> t1, t2;
        t1.push(root);
        while(!t1.empty()||!t2.empty()) {
            vector<int> t;
            if(!t1.empty()) {
                while(!t1.empty()) {
                    t.push_back(t1.front()->val);
                    if(t1.front()->left) t2.push(t1.front()->left);
                    if(t1.front()->right) t2.push(t1.front()->right);
                    t1.pop();
                }
            } else {
                while(!t2.empty()) {
                    t.push_back(t2.front()->val);
                    if(t2.front()->left) t1.push(t2.front()->left);
                    if(t2.front()->right) t1.push(t2.front()->right);
                    t2.pop();
                }
            }
            temp.push_front(t);
        }
        return vector<vector<int>> {temp.begin(), temp.end()};
    }
};