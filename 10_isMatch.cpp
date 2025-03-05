class Solution {
public:
    bool isMatch(string s, string p) {
        // 初始化记忆表，-1 表示未计算过
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s, p, 0, 0, memo);
    }
    
private:
    bool dfs (string& s, string& p, int cs, int cp, vector<vector<int>>& memo) {
        // 查找记忆表
        if (memo[cs][cp] != -1) return memo[cs][cp];
            
        // 终点
        if (cs == s.size()) {
            if (cp + 2 >= p.size()) {
                return memo[cs][cp] = (cp == p.size() || (cp + 2 == p.size() && p[cp + 1] == '*') || (cp + 1 == p.size() && p[cp] == '*'));
            }
            if (p[cp] == '*') return memo[cs][cp] = dfs(s, p, cs, cp + 1, memo);
            if (p[cp + 1] == '*') return memo[cs][cp] = dfs(s, p, cs, cp + 2, memo);
            return memo[cs][cp] = false;
        }
    
        // 匹配
        if ((p[cp] == s[cs] || p[cp] == '.') && dfs(s, p, cs + 1, cp + 1, memo)) {
            return memo[cs][cp] = true;
        }
    
        if (p[cp] == '*') {
            for (int i = cs; i < s.size(); i++) {
                if (p[cp - 1] != '.' && p[cp - 1] != s[i]) break;
                if (dfs(s, p, i + 1, cp + 1, memo)) {
                    return memo[cs][cp] = true;
                }
            }
        }
    
        // 跳过
        if ((p[cp] == s[cs] || p[cp] == '.') && cp + 1 < p.size() && p[cp + 1] == '*' && dfs(s, p, cs + 1, cp + 2, memo)) {
            return memo[cs][cp] = true;
        }
    
        if (cp + 1 < p.size() && p[cp + 1] == '*' && dfs(s, p, cs, cp + 2, memo)) {
            return memo[cs][cp] = true;
        }
    
        // 失败
        return memo[cs][cp] = false;
    }
};
