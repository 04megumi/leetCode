class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; vector<int> t;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++) dfs(ans,nums,t,i,0);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& t, int n, int index) {
        if(t.size()==n) {
            ans.push_back(t);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            if(i>index&&nums[i]==nums[i-1]) continue;
            t.push_back(nums[i]);
            dfs(ans,nums,t,n,i+1);
            t.pop_back();
        }
    }
};