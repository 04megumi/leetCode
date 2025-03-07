class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs[0].size();i++) {
            if(!isLegal(strs, i, strs[0][i])) return ans;
            ans += strs[0][i];
        }
        return ans;
    }

    bool isLegal(vector<string> strs, int pos, char key) {
        for(string str : strs) {
            if(str.size()<pos) return false;
            if(str[pos]!=key) return false;
        }
        return true;
    }
};
