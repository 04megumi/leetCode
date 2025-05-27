class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int n = s1.size();
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(n,false)));
        for(int len=1;len<=n;len++) {
            for(int i=0;i+len<=n;i++) {
                for(int j=0;j+len<=n;j++) {
                    if(len==1) {
                        dp[i][j][0] = s1[i]==s2[j];
                        continue;
                    }
                    for(int k=1;k<len;k++) {
                        if(dp[i][j][len-1]) break;
                        dp[i][j][len-1] = dp[i][j][len-1]||dp[i][j][k-1]&&dp[i+k][j+k][len-k-1];
                        dp[i][j][len-1] = dp[i][j][len-1]||dp[i][j+len-k][k-1]&&dp[i+k][j][len-k-1];
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};