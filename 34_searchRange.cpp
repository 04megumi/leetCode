class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = -1, ans2 = -1;
        int l = 0, r = nums.size()-1;
        while(l<=r) {
            int m = (l+r) >> 1;
            if(nums[m]==target) {
                if(!m) {
                    ans1 = 0;
                    break;
                }
                if(nums[m-1]!=target) {
                    ans1 = m;
                    break;
                }
                r = m-1;
                continue;
            }
            if(nums[m]<target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        l = 0, r = nums.size()-1;
        while(l<=r) {
            int m = (l+r) >> 1;
            if(nums[m]==target) {
                if(m==nums.size()-1) {
                    ans2 = nums.size()-1;
                    break;
                }
                if(nums[m+1]!=target) {
                    ans2 = m;
                    break;
                }
                l = m+1;
                continue;
            }
            if(nums[m]<target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return {ans1, ans2};
    }
};
