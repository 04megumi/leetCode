class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int m = (l+r) >> 1;
            if(nums[l] > nums[r]) {
                if(nums[m] >= nums[l]) {
                    l = m+1;
                } else {
                    r = m;
                }
            } else {
                return nums[l];
            }
        }
        return nums[l];
    }
};