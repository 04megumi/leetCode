class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> prefix(needle.size());
        getPrefix(prefix,needle);
        int i = 0, j = 0;

        while(i<haystack.size() && j<needle.size()) {
            if(haystack[i]==needle[j]) {
                i++, j++;
            } else {
                if(!j) {
                    i++;
                } else {
                    j = prefix[j-1]+1;
                }
            }
        }

        return j==needle.size() ? i-j : -1;
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
