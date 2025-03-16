class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minSum = abs(nums[0]+nums[1]+nums[2]-target);
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++) {
            int l=i+1, r=nums.size()-1;
            while(l<r) {
                int s=nums[i]+nums[l]+nums[r];
                if(s==target) return target;
                ans = abs(s-target)<minSum ? s : ans;
                minSum = min(minSum, abs(s-target));
                if(s>target) {
                    r--;
                } else {
                    l++;
                }   
            }
        }
        return ans;
    }
};
