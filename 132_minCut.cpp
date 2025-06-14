class Solution {
private:
    vector<vector<bool>> dp;
    vector<int> dp2;
public:
    int minCut(string s) {
        const int n = s.size();
        dp.resize(n,vector<bool>(n,true));
        for(int i=2;i<=n;i++) {
            for(int j=0;i+j-1<n;j++) {
                if(s[j]!=s[i+j-1]) {
                    dp[j][j+i-1] = false;
                } else {
                    dp[j][j+i-1] = i==2?true:dp[j+1][i+j-2];
                }
            }
        }
        dp2.resize(n,INT_MAX);
        for(int i=0;i<n;i++) {
            if(dp[0][i]) {
                dp2[i] = 0;
            } else {
                for(int j=0;j<i;j++) 
                    if(dp[j+1][i]) dp2[i] = min(dp2[i],dp2[j]+1);
            }
        }
        return dp2[n-1];
    }
};