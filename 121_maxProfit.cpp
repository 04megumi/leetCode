class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre = prices[0], ans = 0;
        for(int i=1;i<prices.size();i++) {
            ans = max(ans,prices[i]-pre);
            pre = min(pre,prices[i]);
        }
        return ans;
    }
};