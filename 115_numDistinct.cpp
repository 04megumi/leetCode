class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long>> dp(t.size()+1,vector<unsigned long>(s.size()+1,0));
        for(int i=0;i<dp[0].size();i++) dp[0][i] = 1;

        for(int i=1;i<dp.size();i++) {
            for(int j=1;j<dp[0].size();j++) {
                if(t[i-1]==s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[t.size()][s.size()];
    }
};