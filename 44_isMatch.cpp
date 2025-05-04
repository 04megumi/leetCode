class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> used(s.size() + 1, vector<bool>(p.size() + 1, false));
        return dfs(0, 0, s, p, used);
    }
    bool dfs(int i, int j, string& s, string& p, vector<vector<bool>>& used) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;
        if (used[i][j]) return false;
        used[i][j] = true;
        if (p[j] != '*') {
            if (i == s.size()) return false;
            if (p[j] != s[i] && p[j] != '?') return false;
            return dfs(i + 1, j + 1, s, p, used);
        }
        for (int t = i; t <= s.size(); t++) {
            if (dfs(t, j + 1, s, p, used)) return true;
        }
        return false;
    }
};