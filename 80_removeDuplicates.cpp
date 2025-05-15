class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int slow = 2;
        for(int fast=2;fast<nums.size();fast++) {
            if(nums[fast]==nums[slow-2]) continue;
            nums[slow++] = nums[fast];
        }
        return slow;
    }
};