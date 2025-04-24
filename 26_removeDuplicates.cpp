class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> allNums;
        int ans = 0;
        for (auto num : nums) {
            if (allNums.count(num)) continue;
            allNums.insert(num);
            nums[ans] = num;
            ans++;
        }
        return ans;
    }
};
