class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        for(int i=0;i<obstacleGrid.size();i++) {
            for(int j=0;j<obstacleGrid[0].size();j++) {
                if(obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    if(i) dp[i][j] += dp[i-1][j];
                    if(j) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }          
};