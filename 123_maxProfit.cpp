class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, pre = prices[prices.size()-1], cur = 0;
        vector<int> dp(prices.size()+1,0);
        for(int i=prices.size()-2;i>=0;i--) {
            cur = max(pre-prices[i],cur);
            pre = max(pre,prices[i]);
            dp[i] = cur;
        }
        pre = prices[0], cur = 0;
        for(int i=1;i<prices.size();i++) {
            cur = max(prices[i]-pre,cur);
            pre = min(prices[i],pre);
            ans = max(ans,cur+dp[i+1]);
        }
        return ans;
    }
};