class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, n = nums.size();
        while(l <= r) {
            int m = (l+r) >> 1;
            if(nums[m]>nums[(m+1)%n]) return nums[(m+1)%n];
            if(nums[l]<=nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return nums[0];
    }
};