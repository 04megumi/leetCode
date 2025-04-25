class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(current);
            return;
        }
            
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) {
                break;  
            }
            current.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};
