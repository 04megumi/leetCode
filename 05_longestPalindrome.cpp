/*

(1) 双指针遍历所有情况 O(n^2)

(2) 第一次遍历 ==> map<char, vector<int>>
    后续只要再一次遍历, 每次只遍历首字母索引
    最好O(n), 最差O(n^2)

*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        vector<vector<int>> map (26, vector<int> ());
        string ans;
        for(int i=0;i<s.size();i++) map[int(s[i])-int('a')].push_back(i);
        for (int l = 0; l < s.size(); l++) {
            for (int r = 0; r < map[int(s[l]) - int('a')].size(); r++) {
                int rightIndex = map[int(s[l]) - int('a')][r];
                if (rightIndex > l) { 
                    if (isLegalPalindrome(l + 1, rightIndex - 1, s)) {
                        int length = rightIndex - l + 1;
                        if (ans.size() < length) {
                            ans = s.substr(l, length);
                        }
                    }
                }
            }
        }
        return ans;
    }

    bool isLegalPalindrome(int l, int r, string s) {
        while(l<r) {
            if(s[l]!=s[r]) return false;
            l++, r--;
        }
        return true;
    }
};
