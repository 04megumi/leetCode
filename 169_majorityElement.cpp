class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, ans = 0;
        for(auto& num : nums) {
            if(!vote) ans = num;
            vote += ans==num ? 1 : -1;
        }
        return ans;
    }
};