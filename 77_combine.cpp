class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(n,ans,temp,k,1);
        return ans;
    }
    void dfs(int& n, vector<vector<int>>&ans, vector<int>& temp, int& k, int index) {
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<=n;i++) {
            if(temp.size()+(n-i)+1<k) return;
            temp.push_back(i);
            dfs(n,ans,temp,k,i+1);
            temp.pop_back();
        }
    }
};