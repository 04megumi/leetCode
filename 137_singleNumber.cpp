class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;++i) {
            int t = 0;
            for(auto& num : nums) t += ((num>>i)&1);
            if(t%3) ans |= (1<<i);
        }
        return ans;
    }
};