class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 不需要找出来峰值, 只需要收敛到一个峰值即可
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[m + 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};