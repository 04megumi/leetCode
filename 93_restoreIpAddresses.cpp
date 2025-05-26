class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans; string temp;
        dfs(ans,temp,s,0,0);
        return ans;
    }
    void dfs(vector<string>& ans, string& temp, string& s, int index, int count) {
        if(count==4&&index==s.size()) {
            ans.push_back(temp);
            return;
        }
        if(index==s.size()||count==4) return;
        string t = temp;
        // case1
        temp += s[index];
        if(count!=3) temp += '.';
        dfs(ans,temp,s,index+1,count+1);
        temp = t;
        // case2
        if(s[index]=='0'||index+1==s.size()) return;
        temp += s[index], temp += s[index+1];
        if(count!=3) temp += '.';
        dfs(ans,temp,s,index+2,count+1);
        temp = t;
        // case3
        if(s[index]=='0'||index+2==s.size()) return;
        int n = (s[index]-'0')*100+(s[index+1]-'0')*10+(s[index+2]-'0');
        if(n>255) return;
        temp += s[index], temp += s[index+1], temp += s[index+2];
        if(count!=3) temp += '.';
        dfs(ans,temp,s,index+3,count+1);
        temp = t;
    }
};