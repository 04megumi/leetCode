class Solution {
public:
    string reverseWords(string s) {
        int c1 = s.size()-1;
        string ans;
        while(c1 >= 0) {
            while(c1>=0&&s[c1]==' ') c1--;
            if(c1<0) break;
            string t;
            while(c1>=0&&s[c1]!=' ') {
                t += s[c1];
                c1--;
            }
            reverse(t.begin(),t.end());
            if(ans!="") ans += " ";
            ans += t;
        }
        return ans;
    }
};