class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(!i && !j) continue;
                if(i && j) {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                } else {
                    if(!i) dp[i][j] = dp[i][j-1] + grid[i][j];
                    if(!j) dp[i][j] = dp[i-1][j] + grid[i][j]; 
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};