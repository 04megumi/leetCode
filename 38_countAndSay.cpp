class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string pre = countAndSay(n-1);
        return basic(pre);
    }
    string basic(string& s) {
        int count = 1;
        string ans = "";
        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1]) {
                count++;
            } else {
                ans += count+'0';
                ans += s[i-1];
                count = 1;
            }
        }
        ans += count+'0';
        ans += s[s.size()-1];
        return ans;
    }
};
