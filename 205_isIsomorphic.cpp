class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash; 
        unordered_set<char> set;         

        for (int i = 0; i < s.size(); i++) {
            if (hash.count(s[i])) {
                if (hash[s[i]] != t[i]) return false;
            } else {
                if (set.count(t[i])) return false;
                hash[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};