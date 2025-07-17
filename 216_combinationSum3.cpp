class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        recur(1,0,k,n);
        return ans;
    }
    void recur(int index, int cur,int k, int n) {
        if(cur==n && temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(cur==n || temp.size()==k) return;
        if(cur+(k-temp.size())*index>n) return;
        for(int i=index;i<=9;i++) {
            if(cur+i<=n) {
                temp.push_back(i);
                recur(i+1,cur+i,k,n);
                temp.pop_back();
            }
        }
    }
};