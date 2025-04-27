class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, result, current);
        return result;
    }
    void dfs(vector<int>& candidates, int target, int index, vector<vector<int>>& result, vector<int>& current) {
        if(!target) {
            result.push_back(current);
            return;
        }
        if(index==candidates.size() || candidates[index]>target) return;
        for(int i=index;i<candidates.size();i++) {
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, result, current);
            current.pop_back();
        }
    }
};