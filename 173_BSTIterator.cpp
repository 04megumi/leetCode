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
class BSTIterator {
vector<int> arr;
int cur = 0;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                arr.push_back(root->val);
                root = root->right;
            }
        }
    }
    
    int next() {
        return arr[cur++];
    }
    
    bool hasNext() {
        return cur<arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */