class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long cur = 1, ans = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            ans += (columnTitle[i] - 'A' + 1) * cur;
            cur *= 26;
        }
        return ans;
    }
};