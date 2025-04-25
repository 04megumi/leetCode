class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        if(i >= 0) {
            int j = nums.size() - 1;
            // 注意这里不能简单的维护最小值， 因为如果最小值小于nums[i]会造成数组倒退
            while(j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }    
        reverse(nums.begin() + i + 1, nums.end());
    }
};
