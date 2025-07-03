class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // 当 k 足够大，相当于无限次交易
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }

        vector<vector<int>> dp(k+1, vector<int>(2, 0));
        for (int j = 0; j <= k; ++j)
            dp[j][1] = INT_MIN;

        for (int price : prices) {
            for (int j = k; j >= 1; --j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price);
            }
        }
        return dp[k][0];
    }
};