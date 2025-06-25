class Solution {
public:
    int compareVersion(string version1, string version2) {
        int c1 = 0, c2 = 0;
        //  两个都没比较完
        while(c1<version1.size() || c2<version2.size()) {
            int t1 = 0, t2 = 0;
            while(c1<version1.size() && version1[c1]!='.') {
                t1 *= 10; t1 += version1[c1]-'0';
                c1 ++;
            }
            while(c2<version2.size() && version2[c2]!='.') {
                t2 *= 10; t2 += version2[c2]-'0';
                c2 ++;
            }
            c1++, c2++;
            if(t1!=t2) return t1>t2 ? 1 : -1;
        }
        return 0;        
    }
};