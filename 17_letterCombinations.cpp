/**
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        if(!digits.size()) return ans;

        ans.reserve(pow(3,digits.size()));
        temp.reserve(digits.size());
        dfs(0,digits,ans,temp);

        return ans;
    }
    void dfs(const short index, const string& digits, vector<string>& ans, string& temp) {
        if(index==digits.size()) {
            ans.push_back(temp);
            return;
        }
        const short cur = digits[index]-'0';
        short s = (cur-2)*3, e = (cur-1)*3;
        s += cur>7 ? 1 : 0;
        e += cur>6 ? (cur-5)>>1 : 0;
        for(int i=s;i<e;i++) {
            temp += 'a'+i;
            dfs(index+1, digits, ans, temp);
            temp.pop_back();
        }
    }
};
