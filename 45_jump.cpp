class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 0;
        for(int i=1;i<nums.size();i++) {
            int ans = INT_MAX;
            for(int j=0;j<i;j++) if(nums[j]+j>=i) ans = min(ans, dp[j]+1);
            dp[i] = ans;
        }
        return dp[nums.size()-1];
    }
};