class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) return addBinary(b,a);
        bool r = false;
        for(int i=0;i<a.size();i++) {
            int t = a[a.size()-1-i]-'0';
            if(i<b.size()) t += b[b.size()-1-i]-'0';
            if(r) t++;
            r = t>1;
            a[a.size()-1-i] = t%2 + '0';
        }
        if(r) {
            string ans = "1";
            ans += a;
            return ans;
        }
        return a;
    }
};