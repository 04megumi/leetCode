/*

(1) 双指针遍历所有情况 O(n^3)

(2) 第一次遍历 ==> map<char, vector<int>>
    后续只要再一次遍历, 每次只遍历首字母索引
    最好O(n^2), 最差O(n^3)

(3) 动态规划 ==> 维护 dp[n][n], begin, maxLen
    
    s[i] != s[j] ==> dp[i][j] = false
    s[i] == s[j] ==> dp[i][j] = j-i<3 ? true : dp[i+1][j-1]

*/
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp (s.size(), vector<bool>(s.size()));
        int begin = 0, maxLen = 1;
        for(int i=0;i<s.size();i++) dp[i][i] = true;

        for(int L=1;L<=s.size();L++) {
            for(int i=0;i<s.size();i++) {
                int j=i+L;
                if(j>=s.size()) break;
                if(s[i]!=s[j]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = j-i<3 ? true : dp[i+1][j-1];
                }
                if(dp[i][j]) {
                    if(L+1>maxLen) {
                        begin = i, maxLen = j-i+1;
                    }
                }
            }
        }
        
        return s.substr(begin, maxLen);
    }
};
