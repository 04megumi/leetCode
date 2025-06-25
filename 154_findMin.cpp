class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;
        while(l < r) {
            int m = (l+r) >> 1;
            if(nums[l] == nums[r]) {
                ans = min(ans,nums[l]);
                l++, r--;
                continue;
            }
            if(nums[l] > nums[r]) {
                if(nums[m]>=nums[l]) {
                    l = m+1;
                } else {
                    r = m;
                }
            } else {
                return min(ans,nums[l]);
            }
        }
        return min(ans,nums[l]);
    }
};