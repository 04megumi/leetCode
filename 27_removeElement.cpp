class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for(auto num : nums) {
            if(num==val) continue;
            nums[ans] = num;
            ans++;
        }
        return ans;
    }
};
