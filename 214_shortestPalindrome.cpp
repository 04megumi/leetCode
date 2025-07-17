class Solution {
public:
    string shortestPalindrome(string s) {
        vector<int> prefix(2*s.size()+1);
        string t1 = s;
        reverse(t1.begin(),t1.end());
        string needle = s+"#"+t1;
        getPrefix(prefix,needle);
        int i = prefix[prefix.size()-1];
        string a = s.substr(i+1,s.size()-i-1);
        reverse(a.begin(),a.end());
        return a+s;
    }
    void getPrefix(vector<int>& prefix, string needle) {
        prefix[0] = -1;
        for(int i=1;i<needle.size();i++) {
            int j = prefix[i-1];
            while(j != -1) {
                if(needle[j+1]!=needle[i]) {
                    j = prefix[j];
                } else {
                    break;
                }
            }
            prefix[i] = needle[j+1]==needle[i]? j+1 : j;
        }
    }
};