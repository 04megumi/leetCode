class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0=0, num1=0;
        for(int i=0;i<nums.size();i++) {
            if(!nums[i]) num0++;
            if(nums[i]==1) num1++;
        }
        for(int i=0;i<num0;i++) nums[i] = 0;
        for(int i=num0;i<num0+num1;i++) nums[i] = 1;
        for(int i=num0+num1;i<nums.size();i++) nums[i] = 2;
    }
};