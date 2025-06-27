class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, cur = 5;
        while(cur <= n) {
            ans += n/cur;
            cur *= 5;
        }
        return ans;
    }
};