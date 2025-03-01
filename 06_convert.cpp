class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1 || numRows==1) return s;
        string ans;
        const int L = 2*numRows - 2;
        for(int i=0;i<numRows;i++) {
            int cur = i;
            while(cur<s.size()) {
                ans += s[cur];
                if(i && i!=numRows-1 && cur+(L-2*cur%L)<s.size())
                    ans += s[cur+(L-2*cur%L)];
                cur += L;
            }
        }
        return ans;
    }
};
