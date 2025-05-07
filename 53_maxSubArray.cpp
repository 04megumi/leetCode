class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = INT_MIN;
        for(auto& num : nums) {
            if(sum < 0) {
                sum = num;
            } else {
                sum += num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};