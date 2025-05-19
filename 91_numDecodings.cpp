class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int pre1 = 1, pre2 = 1;
        for(int i=1;i<s.size();i++) {
            int t1 = s[i]=='0'?0:pre1;
            int t2 = (s[i-1]=='1')||(s[i-1]=='2'&&s[i]<='6')?pre2:0;
            pre2 = pre1, pre1 = t1+t2;
        }
        return pre1;
    }
};