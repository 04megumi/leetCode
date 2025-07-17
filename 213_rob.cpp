class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(rob(nums,0,n-2),rob(nums,1,n-1));
    }
    int rob(vector<int>& nums, int s, int e) {
        vector<vector<int>> dp(e-s+1,vector<int>(2));
        dp[0][0] = 0, dp[0][1] = nums[s];
        for(int i=1;i<=e-s;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[s+i];
        }
        return max(dp[e-s][0],dp[e-s][1]);
    }
};