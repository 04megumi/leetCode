class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n) return uniquePaths(n,m);
        long long ans = 1;
        for(int i=1;i<=m-1;i++) ans = ans * (m+n-1-i)/i;
        return int(ans);
    }
};