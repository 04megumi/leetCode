class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size());
        return dfs(0, nums, visited);
    }
    bool dfs(int cur, vector<int>& nums, vector<bool>& visited) {
        if(cur==nums.size()-1 || nums[cur]+cur>=nums.size()-1) return true;
        visited[cur] = true;
        for(int i=1;i<=nums[cur];i++) if(!visited[cur+i]&&dfs(cur+i, nums, visited)) return true;
        return false;
    }
};