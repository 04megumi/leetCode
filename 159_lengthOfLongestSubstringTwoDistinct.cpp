class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> hash;
        int l = 0, r = 0, ans = 0;
        while (r < s.size()) {
            hash[s[r]]++;
            while (hash.size() > 2) {
                hash[s[l]]--;
                if (hash[s[l]] == 0)
                    hash.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};