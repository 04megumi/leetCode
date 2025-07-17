class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, l = 0, cur = 0;
        for(int i=0;i<nums.size();i++) {
            cur += nums[i];
            if(cur>=target) {
                ans = min(ans,i-l+1);
                while(cur>=target) {cur-=nums[l], l++;}
                ans = min(ans,i-l+2);
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};