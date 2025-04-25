class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r) {
            int m = (l+r) >> 1;
            if(nums[m]==target) return m;
            if(!m) {
                if(nums[m]>target) return 0;
                l = 1;
                continue;
            }
            if(nums[m]>target) {
                if(nums[m-1]<target) return m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return nums.size();
    }
};
