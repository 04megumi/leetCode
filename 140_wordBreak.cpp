class Solution {
private:
    int n;
    vector<vector<int>> dp;
    vector<bool> dp2;
    unordered_set<string> set;
    vector<string> ans;
    string temp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size(); dp.resize(n); dp2.resize(n);
        for(auto& t : wordDict) set.insert(t);
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=i;j--) {
                if((j==n-1||dp2[j+1])&&set.find(s.substr(i,j-i+1))!=set.end()) {
                    dp2[i] = true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) for(int j=i;j<n;j++) if(dp2[i]&&set.find(s.substr(i,j-i+1))!=set.end()) dp[i].push_back(j);
        if(dp2[0]) dfs(0,s);
        return ans;
    }
    void dfs(int cur, string& s) {
        if(cur==n) {
            ans.push_back(temp);
            return;
        }
        for(auto& num : dp[cur]) {
            string remind = temp;
            temp += s.substr(cur,num-cur+1);
            if(num!=n-1) temp += " ";
            dfs(num+1,s);
            temp = remind;
        }
    }
};