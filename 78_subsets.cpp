class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<=nums.size();i++) combine(ans, nums, i);
        return ans;
    }
    void combine(vector<vector<int>>& ans,vector<int>& nums, int k) {
        vector<int> temp;
        dfs(nums,ans,temp,k,1);
    }
    void dfs(vector<int>& nums, vector<vector<int>>&ans, vector<int>& temp, int& k, int index) {
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<=nums.size();i++) {
            if(temp.size()+(nums.size()-i)+1<k) return;
            temp.push_back(nums[i-1]);
            dfs(nums,ans,temp,k,i+1);
            temp.pop_back();
        }
    }
};