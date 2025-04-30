class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.size() || s.size()==1) return 0;
        int ans = 0;
        for(int i=0;i<s.size()-1;i++) {
            if(s[i]==')') continue;
            int t = 0;
            int count = 1;
            for(int j=i+1;j<s.size();j++) {
                if(s[j]=='(') {
                    count++;
                    continue;
                }
                if(!count) break;
                if(!--count) t = max(t, j-i+1);
            }
            ans = max(ans, t);
        }
        return ans;
    }
};