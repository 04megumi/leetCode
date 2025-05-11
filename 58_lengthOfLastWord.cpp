class Solution {
public:
    int lengthOfLastWord(string s) {
        int p=s.size(), r;
        while(--p>=0 && s[p]==' ');
        r = p;
        while(--p>=0 && s[p]!=' ');
        return r-p;
    }
};