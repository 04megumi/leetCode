class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1) return target==nums[0];
        int l=0, r=nums.size()-1;
        while(l<=r) {
            // 防止区间长度为2，长度大于等于3的时候必然有一个升序区间
            if(r-l==1) return target==nums[l]||target==nums[r];
            int m = (l+r)>>1;
            if(nums[m]==target) return true;
            // 无法判断哪个区间是升序, 舍弃l, r
            if(nums[m]==nums[l] && nums[m]==nums[r]) {
                l++,r--;
                continue;
            }
            if(nums[l]<=nums[m]) {
                if(target<nums[m]&&target>=nums[l]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                if(target>nums[m]&&target<=nums[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }
        return false;
    }
};