class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans; unordered_map<int,int> hash;
        int temp = 0;
        for(int i=0;i<s.size();i++) {
            temp &= 0x3ffff;
            temp <<= 2;
            if(s[i]=='C') {
                temp |= 1;
            } else if(s[i]=='G') {
                temp |= 2;
            } else if(s[i]=='T') {
                temp |= 3;
            }
            if(i<9) continue;
            if(hash.find(temp)!=hash.end()) {
                if(hash[temp]==1) {
                    ans.push_back(s.substr(i-9,10));
                    hash[temp] = 2;
                }
            } else {
                hash[temp] = 1;
            }
        }
        return ans;
    }
};