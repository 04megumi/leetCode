class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n));
        int t=0, b=n-1, l=0, r=n-1, c=0;
        while(l<=r && t<=b) {
            for(int i=l;i<=r;i++) ans[t][i] = ++c;
            t++;
            if(t>b) break;
            for(int i=t;i<=b;i++) ans[i][r] = ++c;
            r--;
            if(l>r) break;
            for(int i=r;i>=l;i--) ans[b][i] = ++c;
            b--;
            if(t>b) break;
            for(int i=b;i>=t;i--) ans[i][l] = ++c;
            l++;
        }
        return ans;
    }
};