class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        for(int i=0;i<n;i++) {
            if(!i) {
                dp[0][0] = 0;
                dp[0][1] = nums[i];
            } else {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};