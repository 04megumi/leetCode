class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> used(n); vector<int> c(n); //(0,0),(1,1)
        dfs(0,ans,used,c,n);
        return ans;
    }
    void dfs(int index, vector<vector<string>>& ans, vector<bool>& used, vector<int>& c, int& n) {
        if(index==n) {
            vector<string> temp, temp2;
            string t;
            for(int i=0;i<n;i++) t += ".";
            for(int i=0;i<n;i++) {
                t[c[i]] = 'Q';
                temp.push_back(t);
                t[c[i]] = '.';
                t[n-1-c[i]] = 'Q';
                temp2.push_back(t);
                t[n-1-c[i]] = '.';
            }
            ans.push_back(temp);
            if(n!=1 && (!(n%2) || c[0]!=(n-1)/2)) ans.push_back(temp2);
        }
        for(int i=0;i<n;i++) {
            if(!index && i>(n-1)/2) break;
            if(!used[i]) {
                bool flag = true;
                for(int j=0;j<index;j++) {
                    if(index-j==abs(i-c[j])) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    used[i] = true;
                    c[index] = i;
                    dfs(index+1,ans,used,c,n);
                    used[i] = false;
                }
            }
        }
    }
};