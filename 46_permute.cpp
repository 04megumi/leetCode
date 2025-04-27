class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size());
        dfs(nums, 0, ans, temp, used);
        return ans;
    }
    void dfs(vector<int>& nums, unsigned char index, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used) {
        if(index==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(used[i]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, index+1, ans, temp, used);
            used[i] = false;
            temp.pop_back();
        }
    }
};