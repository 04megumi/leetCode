class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        const int l = s.size(), n = words[0].size(), m = words.size();
        
        for (int i=0;i<n&&i+n*m<=l;i++) {
            // 放在内层防止外层循环未清空
            unordered_map<string, int> hashmap;
            for(int j=0;j<m;j++) hashmap[s.substr(i+j*n,n)]++;
            for(auto& word : words) if(!--hashmap[word]) hashmap.erase(word);
            if(hashmap.empty()) ans.push_back(i);
            for(int j=i+n;j+n*m<=l;j+=n) {
                if(!--hashmap[s.substr(j-n,n)]) hashmap.erase(s.substr(j-n,n));
                if(!++hashmap[s.substr(j+(m-1)*n,n)]) hashmap.erase(s.substr(j+(m-1)*n,n));
                if(hashmap.empty()) ans.push_back(j);
            }
        }

        return ans;
    }
};
