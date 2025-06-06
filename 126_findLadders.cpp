class Solution {
private:
    unordered_set<string> wordMap;
    vector<vector<string>> ans;
    unordered_map<string,unordered_set<string>> edges;
    deque<string> tans;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0;i<wordList.size();i++) wordMap.insert(wordList[i]);
        if(wordMap.find(endWord)==wordMap.end()) return ans;
        const int len = beginWord.size(); bool flag = false;
        queue<string> q; q.push(beginWord);
        while(!q.empty()&&!flag) {
            int size = q.size();
            unordered_set<string> temp;
            for(int i=0;i<size;i++) {
                string cur = q.front(); q.pop();
                for(int j=0;j<len;j++) {
                    string t = cur;
                    for(char c='a';c<='z';c++) {
                        t[j] = c;
                        if(wordMap.find(t)!=wordMap.end()) {
                            if(t==endWord) flag = true;
                            edges[t].insert(cur);
                            if(temp.find(t)==temp.end()) q.push(t);
                            temp.insert(t);
                        } 
                    }
                }
            }
            for(auto& word:temp) wordMap.erase(word);
        }
        if(!flag) return ans;
        dfs(endWord,beginWord);
        return ans;
    }
    void dfs(string word, string& beginWord) {
        tans.push_back(word);
        if(word==beginWord) {
            ans.push_back(vector<string>(tans.rbegin(),tans.rend()));
            tans.pop_back();
            return;
        }
        for(auto& word : edges[word]) dfs(word, beginWord);
        tans.pop_back();
    }
};