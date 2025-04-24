class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;

        for(int i=0;i+needle.size()<=haystack.size();i++) {
            bool flag = true;
            for (int j=0;j<needle.size();j++) {
                if(needle[j]!=haystack[i+j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }

        return -1;
    }
};
