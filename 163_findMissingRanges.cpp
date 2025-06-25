class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int l = lower;
        vector<vector<int>> ans;
        for(auto& num : nums) {
            if(l < num) 
                ans.push_back(vector<int>{l, num-1});
            l = num+1;
        }
        if(l<=upper) ans.push_back(vector<int>{l, upper});
        return ans;
    }
};