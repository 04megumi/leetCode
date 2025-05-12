class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = 1, p = digits.size()-1;
        while(p>=0 && r) {
            digits[p] += r;
            r = digits[p]/10;
            digits[p] %= 10;
            p--;
        }
        if(p==-1 && r) {
            vector<int> ans;
            ans.push_back(r);
            for(auto& t : digits) ans.push_back(t);
            return ans;
        }
        return digits;
    }
};