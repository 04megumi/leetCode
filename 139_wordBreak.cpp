class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set; vector<bool> dp(s.size(),false);
        for(auto& t : wordDict) set.insert(t);
        for(int i=0;i<s.size();i++) {
            for(int j=0;j<=i;j++) {
                if((!j||dp[j-1])&&set.find(s.substr(j,i-j+1))!=set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()-1];
    }
};