class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<r-1) {
            int m = (l+r) >> 1;
            if(target==nums[m]) return m;
            // 断点在右区间，左边可信
            if(nums[m]>nums[0] ) {
                if(target<nums[m] && target>=nums[0]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else { 
                if(target>nums[m] && target<=nums[nums.size()-1]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }
        if(nums[l]==target) return l;
        if(nums[r]==target) return r;
        return -1;
    }
};
