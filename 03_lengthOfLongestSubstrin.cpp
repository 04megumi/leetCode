/*
    第7行很关键, 注意不要因为hashMap退到left之前
    这个算大的核心要点就是，left的递增性，即一旦更新left就没有必要再回退
    原因是left每次更新都是因为已经出现重复，如果再回退，并且i还在递增就必然有重复，
    
    left不能出现在必然会重复的位置
*/

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int ans=0, left=0;
            unordered_map<char, int> hashMap;
            for(int i=0;i<s.length();i++){
                if(hashMap.count(s[i])) left = max(left, hashMap[s[i]]+1);
                hashMap[s[i]] = i;
                ans = max(ans, i - left + 1);
            }
            return ans;
        }
    };
