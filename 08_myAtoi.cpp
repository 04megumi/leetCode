class Solution {
public:
    int myAtoi(string s) {
        // 处理长度0边界
        if(!s.size()) return 0;
        const int upper = 2147483647;
        bool isMinus = false;
        int cur = -1, ans = 0;
        // 找符号
        while(++cur < s.size()) {
            if(s[cur] == '-') { isMinus = true; break;}
            if(s[cur] == '+') break;
            if('0'<=s[cur] && s[cur]<='9') { ans+= s[cur]-'0'; break;}
            if(s[cur] == ' ') continue;
            return 0;
        }
        if(cur == s.size()-1) return ans;
        // 处理数据
        for(int i= cur+1;i<s.size();i++) {
            if('0'<=s[i] && s[i]<='9') {
                if(ans > upper/10) return isMinus ? -upper-1 :upper;
                ans *= 10;
                if(ans/10 == upper/10 && s[i]-'0'>7) return isMinus ? -upper-1 :upper;
                ans += s[i]-'0';
                continue;
            }
            break;
        }
        return isMinus ? -ans : ans;
    }
};
