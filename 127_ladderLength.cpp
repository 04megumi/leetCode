class Solution {
private:
    unordered_set<string> wordMap;
    int ans = 1;    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0;i<wordList.size();i++) wordMap.insert(wordList[i]);
        if(wordMap.find(endWord)==wordMap.end()) return 0;
        queue<string> q; q.push(beginWord);
        while(!q.empty()) {
            ans++; int size = q.size();
            vector<string> used;
            unordered_set<string> temp;
            for(int i=0;i<size;i++) {
                string cur = q.front(); q.pop();
                int len = beginWord.size();
                for(int j=0;j<len;j++) {
                    string t=cur;
                    for(char c='a';c<='z';c++) {
                        t[j] = c;
                        if(t==endWord) return ans;
                        if(wordMap.find(t)!=wordMap.end()) {
                            if(temp.find(t)==temp.end()) used.push_back(t);
                            if(temp.find(t)==temp.end()) q.push(t);
                            temp.insert(t);
                        }
                    }
                }
            }
            for(auto& word : temp) wordMap.erase(word);
        }
        return 0;
    }
};