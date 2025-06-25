class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size()) return isOneEditDistance(t, s);
        if (t.size() - s.size() > 1) return false;
        if (t.size() == s.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] != t[i]) diff++;
            return diff == 1;
        } else {
            int n = s.size();
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i])
                    return s.substr(i) == t.substr(i + 1);
            }
            return true;
        }
    }
};